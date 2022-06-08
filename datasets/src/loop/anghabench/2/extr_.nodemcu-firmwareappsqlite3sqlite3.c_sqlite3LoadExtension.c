#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int /*<<< orphan*/  sqlite3_vfs ;
typedef  int (* sqlite3_loadext_entry ) (TYPE_1__*,char**,int /*<<< orphan*/ *) ;
struct TYPE_6__ {int flags; int nExtension; int /*<<< orphan*/ ** aExtension; int /*<<< orphan*/ * pVfs; } ;
typedef  TYPE_1__ sqlite3 ;
typedef  int /*<<< orphan*/  handle ;

/* Variables and functions */
 int SQLITE_ERROR ; 
 int SQLITE_LoadExtension ; 
 int SQLITE_NOMEM_BKPT ; 
 int SQLITE_OK ; 
 int SQLITE_OK_LOAD_PERMANENTLY ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  sqlite3Apis ; 
 int /*<<< orphan*/  sqlite3DbFree (TYPE_1__*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ ** sqlite3DbMallocZero (TYPE_1__*,int) ; 
 scalar_t__ sqlite3Isalpha (int) ; 
 int /*<<< orphan*/  sqlite3OsDlClose (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sqlite3OsDlError (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/ * sqlite3OsDlOpen (int /*<<< orphan*/ *,char const*) ; 
 int sqlite3OsDlSym (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*) ; 
 int sqlite3Strlen30 (char const*) ; 
 int* sqlite3UpperToLower ; 
 int /*<<< orphan*/  sqlite3_free (char*) ; 
 char* sqlite3_malloc64 (int) ; 
 char* sqlite3_mprintf (char*,...) ; 
 int /*<<< orphan*/  sqlite3_snprintf (int,char*,char*,char const*,...) ; 
 scalar_t__ sqlite3_strnicmp (char const*,char*,int) ; 

__attribute__((used)) static int sqlite3LoadExtension(
  sqlite3 *db,          /* Load the extension into this database connection */
  const char *zFile,    /* Name of the shared library containing extension */
  const char *zProc,    /* Entry point.  Use "sqlite3_extension_init" if 0 */
  char **pzErrMsg       /* Put error message here if not 0 */
){
  sqlite3_vfs *pVfs = db->pVfs;
  void *handle;
  sqlite3_loadext_entry xInit;
  char *zErrmsg = 0;
  const char *zEntry;
  char *zAltEntry = 0;
  void **aHandle;
  u64 nMsg = 300 + sqlite3Strlen30(zFile);
  int ii;
  int rc;

  /* Shared library endings to try if zFile cannot be loaded as written */
  static const char *azEndings[] = {
#if SQLITE_OS_WIN
     "dll"
#elif defined(__APPLE__)
     "dylib"
#else
     "so"
#endif
  };


  if( pzErrMsg ) *pzErrMsg = 0;

  /* Ticket #1863.  To avoid a creating security problems for older
  ** applications that relink against newer versions of SQLite, the
  ** ability to run load_extension is turned off by default.  One
  ** must call either sqlite3_enable_load_extension(db) or
  ** sqlite3_db_config(db, SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION, 1, 0)
  ** to turn on extension loading.
  */
  if( (db->flags & SQLITE_LoadExtension)==0 ){
    if( pzErrMsg ){
      *pzErrMsg = sqlite3_mprintf("not authorized");
    }
    return SQLITE_ERROR;
  }

  zEntry = zProc ? zProc : "sqlite3_extension_init";

  handle = sqlite3OsDlOpen(pVfs, zFile);
#if SQLITE_OS_UNIX || SQLITE_OS_WIN
  for(ii=0; ii<ArraySize(azEndings) && handle==0; ii++){
    char *zAltFile = sqlite3_mprintf("%s.%s", zFile, azEndings[ii]);
    if( zAltFile==0 ) return SQLITE_NOMEM_BKPT;
    handle = sqlite3OsDlOpen(pVfs, zAltFile);
    sqlite3_free(zAltFile);
  }
#endif
  if( handle==0 ){
    if( pzErrMsg ){
      *pzErrMsg = zErrmsg = sqlite3_malloc64(nMsg);
      if( zErrmsg ){
        sqlite3_snprintf(nMsg, zErrmsg,
            "unable to open shared library [%s]", zFile);
        sqlite3OsDlError(pVfs, nMsg-1, zErrmsg);
      }
    }
    return SQLITE_ERROR;
  }
  xInit = (sqlite3_loadext_entry)sqlite3OsDlSym(pVfs, handle, zEntry);

  /* If no entry point was specified and the default legacy
  ** entry point name "sqlite3_extension_init" was not found, then
  ** construct an entry point name "sqlite3_X_init" where the X is
  ** replaced by the lowercase value of every ASCII alphabetic
  ** character in the filename after the last "/" upto the first ".",
  ** and eliding the first three characters if they are "lib".
  ** Examples:
  **
  **    /usr/local/lib/libExample5.4.3.so ==>  sqlite3_example_init
  **    C:/lib/mathfuncs.dll              ==>  sqlite3_mathfuncs_init
  */
  if( xInit==0 && zProc==0 ){
    int iFile, iEntry, c;
    int ncFile = sqlite3Strlen30(zFile);
    zAltEntry = sqlite3_malloc64(ncFile+30);
    if( zAltEntry==0 ){
      sqlite3OsDlClose(pVfs, handle);
      return SQLITE_NOMEM_BKPT;
    }
    memcpy(zAltEntry, "sqlite3_", 8);
    for(iFile=ncFile-1; iFile>=0 && zFile[iFile]!='/'; iFile--){}
    iFile++;
    if( sqlite3_strnicmp(zFile+iFile, "lib", 3)==0 ) iFile += 3;
    for(iEntry=8; (c = zFile[iFile])!=0 && c!='.'; iFile++){
      if( sqlite3Isalpha(c) ){
        zAltEntry[iEntry++] = (char)sqlite3UpperToLower[(unsigned)c];
      }
    }
    memcpy(zAltEntry+iEntry, "_init", 6);
    zEntry = zAltEntry;
    xInit = (sqlite3_loadext_entry)sqlite3OsDlSym(pVfs, handle, zEntry);
  }
  if( xInit==0 ){
    if( pzErrMsg ){
      nMsg += sqlite3Strlen30(zEntry);
      *pzErrMsg = zErrmsg = sqlite3_malloc64(nMsg);
      if( zErrmsg ){
        sqlite3_snprintf(nMsg, zErrmsg,
            "no entry point [%s] in shared library [%s]", zEntry, zFile);
        sqlite3OsDlError(pVfs, nMsg-1, zErrmsg);
      }
    }
    sqlite3OsDlClose(pVfs, handle);
    sqlite3_free(zAltEntry);
    return SQLITE_ERROR;
  }
  sqlite3_free(zAltEntry);
  rc = xInit(db, &zErrmsg, &sqlite3Apis);
  if( rc ){
    if( rc==SQLITE_OK_LOAD_PERMANENTLY ) return SQLITE_OK;
    if( pzErrMsg ){
      *pzErrMsg = sqlite3_mprintf("error during initialization: %s", zErrmsg);
    }
    sqlite3_free(zErrmsg);
    sqlite3OsDlClose(pVfs, handle);
    return SQLITE_ERROR;
  }

  /* Append the new shared library handle to the db->aExtension array. */
  aHandle = sqlite3DbMallocZero(db, sizeof(handle)*(db->nExtension+1));
  if( aHandle==0 ){
    return SQLITE_NOMEM_BKPT;
  }
  if( db->nExtension>0 ){
    memcpy(aHandle, db->aExtension, sizeof(handle)*db->nExtension);
  }
  sqlite3DbFree(db, db->aExtension);
  db->aExtension = aHandle;

  db->aExtension[db->nExtension++] = handle;
  return SQLITE_OK;
}