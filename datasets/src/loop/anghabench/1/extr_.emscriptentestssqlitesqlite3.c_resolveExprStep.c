#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_43__   TYPE_9__ ;
typedef  struct TYPE_42__   TYPE_8__ ;
typedef  struct TYPE_41__   TYPE_7__ ;
typedef  struct TYPE_40__   TYPE_6__ ;
typedef  struct TYPE_39__   TYPE_5__ ;
typedef  struct TYPE_38__   TYPE_4__ ;
typedef  struct TYPE_37__   TYPE_3__ ;
typedef  struct TYPE_36__   TYPE_2__ ;
typedef  struct TYPE_35__   TYPE_1__ ;
typedef  struct TYPE_34__   TYPE_18__ ;
typedef  struct TYPE_33__   TYPE_13__ ;
typedef  struct TYPE_32__   TYPE_12__ ;
typedef  struct TYPE_31__   TYPE_11__ ;
typedef  struct TYPE_30__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_35__ {TYPE_10__* pNC; } ;
struct TYPE_41__ {TYPE_9__* pParse; TYPE_1__ u; } ;
typedef  TYPE_7__ Walker ;
struct TYPE_43__ {scalar_t__ nTab; TYPE_18__* db; scalar_t__ nErr; } ;
struct TYPE_42__ {scalar_t__ nAlloc; int nSrc; TYPE_2__* a; } ;
struct TYPE_40__ {int /*<<< orphan*/  pSelect; TYPE_12__* pList; } ;
struct TYPE_39__ {char const* zToken; } ;
struct TYPE_37__ {char* zToken; } ;
struct TYPE_38__ {TYPE_3__ u; } ;
struct TYPE_36__ {scalar_t__ iCursor; } ;
struct TYPE_34__ {scalar_t__ mallocFailed; } ;
struct TYPE_33__ {int op; TYPE_6__ x; TYPE_5__ u; struct TYPE_33__* pRight; TYPE_4__* pLeft; } ;
struct TYPE_32__ {int nExpr; } ;
struct TYPE_31__ {int /*<<< orphan*/  zName; int /*<<< orphan*/  xFunc; } ;
struct TYPE_30__ {int allowAgg; int hasAgg; int nRef; int /*<<< orphan*/  isCheck; int /*<<< orphan*/  nErr; TYPE_8__* pSrcList; TYPE_9__* pParse; } ;
typedef  TYPE_8__ SrcList ;
typedef  TYPE_9__ Parse ;
typedef  TYPE_10__ NameContext ;
typedef  TYPE_11__ FuncDef ;
typedef  TYPE_12__ ExprList ;
typedef  TYPE_13__ Expr ;

/* Variables and functions */
 int /*<<< orphan*/  ENC (TYPE_18__*) ; 
 int /*<<< orphan*/  EP_Resolved ; 
 int /*<<< orphan*/  EP_VarSelect ; 
 int /*<<< orphan*/  EP_xIsSelect ; 
 scalar_t__ ExprHasAnyProperty (TYPE_13__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExprHasProperty (TYPE_13__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExprSetProperty (TYPE_13__*,int /*<<< orphan*/ ) ; 
 int SQLITE_DENY ; 
 int /*<<< orphan*/  SQLITE_FUNCTION ; 
 int SQLITE_OK ; 
 int const TK_AGG_FUNCTION ; 
#define  TK_CONST_FUNC 135 
#define  TK_DOT 134 
#define  TK_EXISTS 133 
#define  TK_FUNCTION 132 
#define  TK_ID 131 
#define  TK_IN 130 
 int const TK_NULL ; 
#define  TK_SELECT 129 
#define  TK_VARIABLE 128 
 int WRC_Abort ; 
 int WRC_Continue ; 
 int WRC_Prune ; 
 int /*<<< orphan*/  assert (int) ; 
 int lookupName (TYPE_9__*,char const*,char const*,char const*,TYPE_10__*,TYPE_13__*) ; 
 int sqlite3AuthCheck (TYPE_9__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3ErrorMsg (TYPE_9__*,char*,...) ; 
 TYPE_11__* sqlite3FindFunction (TYPE_18__*,char const*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sqlite3Strlen30 (char const*) ; 
 int /*<<< orphan*/  sqlite3WalkExprList (TYPE_7__*,TYPE_12__*) ; 
 int /*<<< orphan*/  sqlite3WalkSelect (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  testcase (int) ; 

__attribute__((used)) static int resolveExprStep(Walker *pWalker, Expr *pExpr){
  NameContext *pNC;
  Parse *pParse;

  pNC = pWalker->u.pNC;
  assert( pNC!=0 );
  pParse = pNC->pParse;
  assert( pParse==pWalker->pParse );

  if( ExprHasAnyProperty(pExpr, EP_Resolved) ) return WRC_Prune;
  ExprSetProperty(pExpr, EP_Resolved);
#ifndef NDEBUG
  if( pNC->pSrcList && pNC->pSrcList->nAlloc>0 ){
    SrcList *pSrcList = pNC->pSrcList;
    int i;
    for(i=0; i<pNC->pSrcList->nSrc; i++){
      assert( pSrcList->a[i].iCursor>=0 && pSrcList->a[i].iCursor<pParse->nTab);
    }
  }
#endif
  switch( pExpr->op ){

#if defined(SQLITE_ENABLE_UPDATE_DELETE_LIMIT) && !defined(SQLITE_OMIT_SUBQUERY)
    /* The special operator TK_ROW means use the rowid for the first
    ** column in the FROM clause.  This is used by the LIMIT and ORDER BY
    ** clause processing on UPDATE and DELETE statements.
    */
    case TK_ROW: {
      SrcList *pSrcList = pNC->pSrcList;
      struct SrcList_item *pItem;
      assert( pSrcList && pSrcList->nSrc==1 );
      pItem = pSrcList->a; 
      pExpr->op = TK_COLUMN;
      pExpr->pTab = pItem->pTab;
      pExpr->iTable = pItem->iCursor;
      pExpr->iColumn = -1;
      pExpr->affinity = SQLITE_AFF_INTEGER;
      break;
    }
#endif /* defined(SQLITE_ENABLE_UPDATE_DELETE_LIMIT) && !defined(SQLITE_OMIT_SUBQUERY) */

    /* A lone identifier is the name of a column.
    */
    case TK_ID: {
      return lookupName(pParse, 0, 0, pExpr->u.zToken, pNC, pExpr);
    }
  
    /* A table name and column name:     ID.ID
    ** Or a database, table and column:  ID.ID.ID
    */
    case TK_DOT: {
      const char *zColumn;
      const char *zTable;
      const char *zDb;
      Expr *pRight;

      /* if( pSrcList==0 ) break; */
      pRight = pExpr->pRight;
      if( pRight->op==TK_ID ){
        zDb = 0;
        zTable = pExpr->pLeft->u.zToken;
        zColumn = pRight->u.zToken;
      }else{
        assert( pRight->op==TK_DOT );
        zDb = pExpr->pLeft->u.zToken;
        zTable = pRight->pLeft->u.zToken;
        zColumn = pRight->pRight->u.zToken;
      }
      return lookupName(pParse, zDb, zTable, zColumn, pNC, pExpr);
    }

    /* Resolve function names
    */
    case TK_CONST_FUNC:
    case TK_FUNCTION: {
      ExprList *pList = pExpr->x.pList;    /* The argument list */
      int n = pList ? pList->nExpr : 0;    /* Number of arguments */
      int no_such_func = 0;       /* True if no such function exists */
      int wrong_num_args = 0;     /* True if wrong number of arguments */
      int is_agg = 0;             /* True if is an aggregate function */
      int auth;                   /* Authorization to use the function */
      int nId;                    /* Number of characters in function name */
      const char *zId;            /* The function name. */
      FuncDef *pDef;              /* Information about the function */
      u8 enc = ENC(pParse->db);   /* The database encoding */

      testcase( pExpr->op==TK_CONST_FUNC );
      assert( !ExprHasProperty(pExpr, EP_xIsSelect) );
      zId = pExpr->u.zToken;
      nId = sqlite3Strlen30(zId);
      pDef = sqlite3FindFunction(pParse->db, zId, nId, n, enc, 0);
      if( pDef==0 ){
        pDef = sqlite3FindFunction(pParse->db, zId, nId, -1, enc, 0);
        if( pDef==0 ){
          no_such_func = 1;
        }else{
          wrong_num_args = 1;
        }
      }else{
        is_agg = pDef->xFunc==0;
      }
#ifndef SQLITE_OMIT_AUTHORIZATION
      if( pDef ){
        auth = sqlite3AuthCheck(pParse, SQLITE_FUNCTION, 0, pDef->zName, 0);
        if( auth!=SQLITE_OK ){
          if( auth==SQLITE_DENY ){
            sqlite3ErrorMsg(pParse, "not authorized to use function: %s",
                                    pDef->zName);
            pNC->nErr++;
          }
          pExpr->op = TK_NULL;
          return WRC_Prune;
        }
      }
#endif
      if( is_agg && !pNC->allowAgg ){
        sqlite3ErrorMsg(pParse, "misuse of aggregate function %.*s()", nId,zId);
        pNC->nErr++;
        is_agg = 0;
      }else if( no_such_func ){
        sqlite3ErrorMsg(pParse, "no such function: %.*s", nId, zId);
        pNC->nErr++;
      }else if( wrong_num_args ){
        sqlite3ErrorMsg(pParse,"wrong number of arguments to function %.*s()",
             nId, zId);
        pNC->nErr++;
      }
      if( is_agg ){
        pExpr->op = TK_AGG_FUNCTION;
        pNC->hasAgg = 1;
      }
      if( is_agg ) pNC->allowAgg = 0;
      sqlite3WalkExprList(pWalker, pList);
      if( is_agg ) pNC->allowAgg = 1;
      /* FIX ME:  Compute pExpr->affinity based on the expected return
      ** type of the function 
      */
      return WRC_Prune;
    }
#ifndef SQLITE_OMIT_SUBQUERY
    case TK_SELECT:
    case TK_EXISTS:  testcase( pExpr->op==TK_EXISTS );
#endif
    case TK_IN: {
      testcase( pExpr->op==TK_IN );
      if( ExprHasProperty(pExpr, EP_xIsSelect) ){
        int nRef = pNC->nRef;
#ifndef SQLITE_OMIT_CHECK
        if( pNC->isCheck ){
          sqlite3ErrorMsg(pParse,"subqueries prohibited in CHECK constraints");
        }
#endif
        sqlite3WalkSelect(pWalker, pExpr->x.pSelect);
        assert( pNC->nRef>=nRef );
        if( nRef!=pNC->nRef ){
          ExprSetProperty(pExpr, EP_VarSelect);
        }
      }
      break;
    }
#ifndef SQLITE_OMIT_CHECK
    case TK_VARIABLE: {
      if( pNC->isCheck ){
        sqlite3ErrorMsg(pParse,"parameters prohibited in CHECK constraints");
      }
      break;
    }
#endif
  }
  return (pParse->nErr || pParse->db->mallocFailed) ? WRC_Abort : WRC_Continue;
}