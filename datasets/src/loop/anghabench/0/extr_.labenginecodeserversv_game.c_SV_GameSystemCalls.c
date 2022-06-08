#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int intptr_t ;
struct TYPE_10__ {int (* BotLoadCharacter ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int (* Characteristic_Integer ) (int,int) ;int (* Characteristic_BInteger ) (int,int,int,int) ;int (* BotAllocChatState ) () ;int (* BotNextConsoleMessage ) (int,int /*<<< orphan*/ *) ;int (* BotNumConsoleMessages ) (int) ;int (* BotNumInitialChats ) (int,int /*<<< orphan*/ *) ;int (* BotReplyChat ) (int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotChatLength ) (int) ;int (* StringContains ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* BotFindMatch ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* BotLoadChatFile ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotGetTopGoal ) (int,int /*<<< orphan*/ *) ;int (* BotGetSecondGoal ) (int,int /*<<< orphan*/ *) ;int (* BotChooseLTGItem ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* BotChooseNBGItem ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int (* BotTouchingGoal ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotItemGoalInVisButNotVisible ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotGetLevelItemGoal ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotGetNextCampSpotGoal ) (int,int /*<<< orphan*/ *) ;int (* BotGetMapLocationGoal ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotLoadItemWeights ) (int,int /*<<< orphan*/ *) ;int (* BotAllocGoalState ) (int) ;int (* BotMoveInDirection ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ;int (* BotReachabilityArea ) (int /*<<< orphan*/ *,int) ;int (* BotMovementViewTarget ) (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;int (* BotPredictVisiblePosition ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ;int (* BotAllocMoveState ) () ;int (* BotChooseBestFightWeapon ) (int,int /*<<< orphan*/ *) ;int (* BotLoadWeaponWeights ) (int,int /*<<< orphan*/ *) ;int (* BotAllocWeaponState ) () ;int (* GeneticParentsAndChildSelection ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotResetWeaponState ) (int) ;int /*<<< orphan*/  (* BotFreeWeaponState ) (int) ;int /*<<< orphan*/  (* BotGetWeaponInfo ) (int,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotInitMoveState ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotFreeMoveState ) (int) ;int /*<<< orphan*/  (* BotResetLastAvoidReach ) (int) ;int /*<<< orphan*/  (* BotResetAvoidReach ) (int) ;int /*<<< orphan*/  (* BotMoveToGoal ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* BotAddAvoidSpot ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* BotResetMoveState ) (int) ;int /*<<< orphan*/  (* BotFreeGoalState ) (int) ;int /*<<< orphan*/  (* BotMutateGoalFuzzyLogic ) (int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* BotSaveGoalFuzzyLogic ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotInterbreedGoalFuzzyLogic ) (int,int,int) ;int /*<<< orphan*/  (* BotFreeItemWeights ) (int) ;int /*<<< orphan*/  (* BotUpdateEntityItems ) () ;int /*<<< orphan*/  (* BotInitLevelItems ) () ;int /*<<< orphan*/  (* BotSetAvoidGoalTime ) (int,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* BotAvoidGoalTime ) (int,int) ;int /*<<< orphan*/  (* BotGoalName ) (int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* BotDumpGoalStack ) (int) ;int /*<<< orphan*/  (* BotDumpAvoidGoals ) (int) ;int /*<<< orphan*/  (* BotEmptyGoalStack ) (int) ;int /*<<< orphan*/  (* BotPopGoal ) (int) ;int /*<<< orphan*/  (* BotPushGoal ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotRemoveFromAvoidGoals ) (int,int) ;int /*<<< orphan*/  (* BotResetAvoidGoals ) (int) ;int /*<<< orphan*/  (* BotResetGoalState ) (int) ;int /*<<< orphan*/  (* BotSetChatName ) (int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* BotSetChatGender ) (int,int) ;int /*<<< orphan*/  (* BotReplaceSynonyms ) (int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* UnifyWhiteSpaces ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotMatchVariable ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* BotGetChatMessage ) (int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* BotEnterChat ) (int,int,int) ;int /*<<< orphan*/  (* BotInitialChat ) (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotRemoveConsoleMessage ) (int,int) ;int /*<<< orphan*/  (* BotQueueConsoleMessage ) (int,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BotFreeChatState ) (int) ;int /*<<< orphan*/  (* Characteristic_String ) (int,int,int /*<<< orphan*/ *,int) ;int /*<<< orphan*/  (* Characteristic_BFloat ) (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* Characteristic_Float ) (int,int) ;int /*<<< orphan*/  (* BotFreeCharacter ) (int) ;} ;
struct TYPE_9__ {int /*<<< orphan*/  (* EA_ResetInput ) (int) ;int /*<<< orphan*/  (* EA_GetInput ) (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* EA_EndRegular ) (int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* EA_View ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* EA_Move ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* EA_DelayedJump ) (int) ;int /*<<< orphan*/  (* EA_Jump ) (int) ;int /*<<< orphan*/  (* EA_SelectWeapon ) (int,int) ;int /*<<< orphan*/  (* EA_MoveRight ) (int) ;int /*<<< orphan*/  (* EA_MoveLeft ) (int) ;int /*<<< orphan*/  (* EA_MoveBack ) (int) ;int /*<<< orphan*/  (* EA_MoveForward ) (int) ;int /*<<< orphan*/  (* EA_MoveDown ) (int) ;int /*<<< orphan*/  (* EA_MoveUp ) (int) ;int /*<<< orphan*/  (* EA_Crouch ) (int) ;int /*<<< orphan*/  (* EA_Respawn ) (int) ;int /*<<< orphan*/  (* EA_Use ) (int) ;int /*<<< orphan*/  (* EA_Attack ) (int) ;int /*<<< orphan*/  (* EA_Talk ) (int) ;int /*<<< orphan*/  (* EA_Gesture ) (int) ;int /*<<< orphan*/  (* EA_Action ) (int,int) ;int /*<<< orphan*/  (* EA_Command ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* EA_SayTeam ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* EA_Say ) (int,int /*<<< orphan*/ *) ;} ;
struct TYPE_8__ {int (* AAS_BBoxAreas ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* AAS_AreaInfo ) (int,int /*<<< orphan*/ *) ;int (* AAS_AlternativeRouteGoals ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int,int) ;int (* AAS_Initialized ) () ;int (* AAS_PointAreaNum ) (int /*<<< orphan*/ *) ;int (* AAS_PointReachabilityAreaIndex ) (int /*<<< orphan*/ *) ;int (* AAS_TraceAreas ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* AAS_PointContents ) (int /*<<< orphan*/ *) ;int (* AAS_NextBSPEntity ) (int) ;int (* AAS_ValueForBSPEpairKey ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* AAS_VectorForBSPEpairKey ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* AAS_FloatForBSPEpairKey ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* AAS_IntForBSPEpairKey ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* AAS_AreaReachability ) (int) ;int (* AAS_AreaTravelTimeToGoalArea ) (int,int /*<<< orphan*/ *,int,int) ;int (* AAS_EnableRoutingArea ) (int,int) ;int (* AAS_PredictRoute ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int,int,int,int,int,int) ;int (* AAS_Swimming ) (int /*<<< orphan*/ *) ;int (* AAS_PredictClientMovement ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ,int,int,int) ;int /*<<< orphan*/  (* AAS_Time ) () ;int /*<<< orphan*/  (* AAS_PresenceTypeBoundingBox ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* AAS_EntityInfo ) (int,int /*<<< orphan*/ *) ;} ;
struct TYPE_14__ {int (* BotLibVarSet ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotLibVarGet ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* PC_AddGlobalDefine ) (int /*<<< orphan*/ *) ;int (* PC_LoadSourceHandle ) (int /*<<< orphan*/ *) ;int (* PC_FreeSourceHandle ) (int) ;int (* PC_ReadTokenHandle ) (int,int /*<<< orphan*/ *) ;int (* PC_SourceFileAndLine ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* BotLibStartFrame ) (int /*<<< orphan*/ ) ;int (* BotLibLoadMap ) (int /*<<< orphan*/ *) ;int (* BotLibUpdateEntity ) (int,int /*<<< orphan*/ *) ;int (* Test ) (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;TYPE_3__ ai; TYPE_2__ ea; TYPE_1__ aas; } ;
struct TYPE_13__ {int /*<<< orphan*/  entityParsePoint; } ;
struct TYPE_12__ {int integer; } ;
struct TYPE_11__ {int /*<<< orphan*/ * clients; } ;

/* Variables and functions */
 int /*<<< orphan*/  AngleVectors (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
#define  BOTLIB_AAS_ALTERNATIVE_ROUTE_GOAL 323 
#define  BOTLIB_AAS_AREA_INFO 322 
#define  BOTLIB_AAS_AREA_REACHABILITY 321 
#define  BOTLIB_AAS_AREA_TRAVEL_TIME_TO_GOAL_AREA 320 
#define  BOTLIB_AAS_BBOX_AREAS 319 
#define  BOTLIB_AAS_ENABLE_ROUTING_AREA 318 
#define  BOTLIB_AAS_ENTITY_INFO 317 
#define  BOTLIB_AAS_FLOAT_FOR_BSP_EPAIR_KEY 316 
#define  BOTLIB_AAS_INITIALIZED 315 
#define  BOTLIB_AAS_INT_FOR_BSP_EPAIR_KEY 314 
#define  BOTLIB_AAS_NEXT_BSP_ENTITY 313 
#define  BOTLIB_AAS_POINT_AREA_NUM 312 
#define  BOTLIB_AAS_POINT_CONTENTS 311 
#define  BOTLIB_AAS_POINT_REACHABILITY_AREA_INDEX 310 
#define  BOTLIB_AAS_PREDICT_CLIENT_MOVEMENT 309 
#define  BOTLIB_AAS_PREDICT_ROUTE 308 
#define  BOTLIB_AAS_PRESENCE_TYPE_BOUNDING_BOX 307 
#define  BOTLIB_AAS_SWIMMING 306 
#define  BOTLIB_AAS_TIME 305 
#define  BOTLIB_AAS_TRACE_AREAS 304 
#define  BOTLIB_AAS_VALUE_FOR_BSP_EPAIR_KEY 303 
#define  BOTLIB_AAS_VECTOR_FOR_BSP_EPAIR_KEY 302 
#define  BOTLIB_AI_ADD_AVOID_SPOT 301 
#define  BOTLIB_AI_ALLOC_CHAT_STATE 300 
#define  BOTLIB_AI_ALLOC_GOAL_STATE 299 
#define  BOTLIB_AI_ALLOC_MOVE_STATE 298 
#define  BOTLIB_AI_ALLOC_WEAPON_STATE 297 
#define  BOTLIB_AI_AVOID_GOAL_TIME 296 
#define  BOTLIB_AI_CHARACTERISTIC_BFLOAT 295 
#define  BOTLIB_AI_CHARACTERISTIC_BINTEGER 294 
#define  BOTLIB_AI_CHARACTERISTIC_FLOAT 293 
#define  BOTLIB_AI_CHARACTERISTIC_INTEGER 292 
#define  BOTLIB_AI_CHARACTERISTIC_STRING 291 
#define  BOTLIB_AI_CHAT_LENGTH 290 
#define  BOTLIB_AI_CHOOSE_BEST_FIGHT_WEAPON 289 
#define  BOTLIB_AI_CHOOSE_LTG_ITEM 288 
#define  BOTLIB_AI_CHOOSE_NBG_ITEM 287 
#define  BOTLIB_AI_DUMP_AVOID_GOALS 286 
#define  BOTLIB_AI_DUMP_GOAL_STACK 285 
#define  BOTLIB_AI_EMPTY_GOAL_STACK 284 
#define  BOTLIB_AI_ENTER_CHAT 283 
#define  BOTLIB_AI_FIND_MATCH 282 
#define  BOTLIB_AI_FREE_CHARACTER 281 
#define  BOTLIB_AI_FREE_CHAT_STATE 280 
#define  BOTLIB_AI_FREE_GOAL_STATE 279 
#define  BOTLIB_AI_FREE_ITEM_WEIGHTS 278 
#define  BOTLIB_AI_FREE_MOVE_STATE 277 
#define  BOTLIB_AI_FREE_WEAPON_STATE 276 
#define  BOTLIB_AI_GENETIC_PARENTS_AND_CHILD_SELECTION 275 
#define  BOTLIB_AI_GET_CHAT_MESSAGE 274 
#define  BOTLIB_AI_GET_LEVEL_ITEM_GOAL 273 
#define  BOTLIB_AI_GET_MAP_LOCATION_GOAL 272 
#define  BOTLIB_AI_GET_NEXT_CAMP_SPOT_GOAL 271 
#define  BOTLIB_AI_GET_SECOND_GOAL 270 
#define  BOTLIB_AI_GET_TOP_GOAL 269 
#define  BOTLIB_AI_GET_WEAPON_INFO 268 
#define  BOTLIB_AI_GOAL_NAME 267 
#define  BOTLIB_AI_INITIAL_CHAT 266 
#define  BOTLIB_AI_INIT_LEVEL_ITEMS 265 
#define  BOTLIB_AI_INIT_MOVE_STATE 264 
#define  BOTLIB_AI_INTERBREED_GOAL_FUZZY_LOGIC 263 
#define  BOTLIB_AI_ITEM_GOAL_IN_VIS_BUT_NOT_VISIBLE 262 
#define  BOTLIB_AI_LOAD_CHARACTER 261 
#define  BOTLIB_AI_LOAD_CHAT_FILE 260 
#define  BOTLIB_AI_LOAD_ITEM_WEIGHTS 259 
#define  BOTLIB_AI_LOAD_WEAPON_WEIGHTS 258 
#define  BOTLIB_AI_MATCH_VARIABLE 257 
#define  BOTLIB_AI_MOVEMENT_VIEW_TARGET 256 
#define  BOTLIB_AI_MOVE_IN_DIRECTION 255 
#define  BOTLIB_AI_MOVE_TO_GOAL 254 
#define  BOTLIB_AI_MUTATE_GOAL_FUZZY_LOGIC 253 
#define  BOTLIB_AI_NEXT_CONSOLE_MESSAGE 252 
#define  BOTLIB_AI_NUM_CONSOLE_MESSAGE 251 
#define  BOTLIB_AI_NUM_INITIAL_CHATS 250 
#define  BOTLIB_AI_POP_GOAL 249 
#define  BOTLIB_AI_PREDICT_VISIBLE_POSITION 248 
#define  BOTLIB_AI_PUSH_GOAL 247 
#define  BOTLIB_AI_QUEUE_CONSOLE_MESSAGE 246 
#define  BOTLIB_AI_REACHABILITY_AREA 245 
#define  BOTLIB_AI_REMOVE_CONSOLE_MESSAGE 244 
#define  BOTLIB_AI_REMOVE_FROM_AVOID_GOALS 243 
#define  BOTLIB_AI_REPLACE_SYNONYMS 242 
#define  BOTLIB_AI_REPLY_CHAT 241 
#define  BOTLIB_AI_RESET_AVOID_GOALS 240 
#define  BOTLIB_AI_RESET_AVOID_REACH 239 
#define  BOTLIB_AI_RESET_GOAL_STATE 238 
#define  BOTLIB_AI_RESET_LAST_AVOID_REACH 237 
#define  BOTLIB_AI_RESET_MOVE_STATE 236 
#define  BOTLIB_AI_RESET_WEAPON_STATE 235 
#define  BOTLIB_AI_SAVE_GOAL_FUZZY_LOGIC 234 
#define  BOTLIB_AI_SET_AVOID_GOAL_TIME 233 
#define  BOTLIB_AI_SET_CHAT_GENDER 232 
#define  BOTLIB_AI_SET_CHAT_NAME 231 
#define  BOTLIB_AI_STRING_CONTAINS 230 
#define  BOTLIB_AI_TOUCHING_GOAL 229 
#define  BOTLIB_AI_UNIFY_WHITE_SPACES 228 
#define  BOTLIB_AI_UPDATE_ENTITY_ITEMS 227 
#define  BOTLIB_EA_ACTION 226 
#define  BOTLIB_EA_ATTACK 225 
#define  BOTLIB_EA_COMMAND 224 
#define  BOTLIB_EA_CROUCH 223 
#define  BOTLIB_EA_DELAYED_JUMP 222 
#define  BOTLIB_EA_END_REGULAR 221 
#define  BOTLIB_EA_GESTURE 220 
#define  BOTLIB_EA_GET_INPUT 219 
#define  BOTLIB_EA_JUMP 218 
#define  BOTLIB_EA_MOVE 217 
#define  BOTLIB_EA_MOVE_BACK 216 
#define  BOTLIB_EA_MOVE_DOWN 215 
#define  BOTLIB_EA_MOVE_FORWARD 214 
#define  BOTLIB_EA_MOVE_LEFT 213 
#define  BOTLIB_EA_MOVE_RIGHT 212 
#define  BOTLIB_EA_MOVE_UP 211 
#define  BOTLIB_EA_RESET_INPUT 210 
#define  BOTLIB_EA_RESPAWN 209 
#define  BOTLIB_EA_SAY 208 
#define  BOTLIB_EA_SAY_TEAM 207 
#define  BOTLIB_EA_SELECT_WEAPON 206 
#define  BOTLIB_EA_TALK 205 
#define  BOTLIB_EA_USE 204 
#define  BOTLIB_EA_VIEW 203 
#define  BOTLIB_GET_CONSOLE_MESSAGE 202 
#define  BOTLIB_GET_SNAPSHOT_ENTITY 201 
#define  BOTLIB_LIBVAR_GET 200 
#define  BOTLIB_LIBVAR_SET 199 
#define  BOTLIB_LOAD_MAP 198 
#define  BOTLIB_PC_ADD_GLOBAL_DEFINE 197 
#define  BOTLIB_PC_FREE_SOURCE 196 
#define  BOTLIB_PC_LOAD_SOURCE 195 
#define  BOTLIB_PC_READ_TOKEN 194 
#define  BOTLIB_PC_SOURCE_FILE_AND_LINE 193 
#define  BOTLIB_SETUP 192 
#define  BOTLIB_SHUTDOWN 191 
#define  BOTLIB_START_FRAME 190 
#define  BOTLIB_TEST 189 
#define  BOTLIB_UPDATENTITY 188 
#define  BOTLIB_USER_COMMAND 187 
 int BotImport_DebugPolygonCreate (int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BotImport_DebugPolygonDelete (int) ; 
 int CM_AreasConnected (int,int) ; 
 char* COM_Parse (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Cbuf_ExecuteText (int,int /*<<< orphan*/ *) ; 
 int Cmd_Argc () ; 
 int /*<<< orphan*/  Cmd_ArgvBuffer (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  Com_Error (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  Com_Memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  Com_Memset (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  Com_Printf (char*,char const*) ; 
 int Com_RealTime (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Cvar_Register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  Cvar_SetSafe (char const*,char const*) ; 
 int /*<<< orphan*/  Cvar_Update (int /*<<< orphan*/ *) ; 
 int Cvar_VariableIntegerValue (char const*) ; 
 int /*<<< orphan*/  Cvar_VariableStringBuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ERR_DROP ; 
 int /*<<< orphan*/  FS_FCloseFile (int) ; 
 int FS_FOpenFileByMode (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int FS_GetFileList (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  FS_Read (int /*<<< orphan*/ *,int,int) ; 
 int FS_Seek (int,int,int) ; 
 int /*<<< orphan*/  FS_Write (int /*<<< orphan*/ *,int,int) ; 
 int FloatAsInt (int /*<<< orphan*/ ) ; 
#define  G_ADJUST_AREA_PORTAL_STATE 186 
#define  G_AREAS_CONNECTED 185 
#define  G_ARGC 184 
#define  G_ARGV 183 
#define  G_BOT_ALLOCATE_CLIENT 182 
#define  G_BOT_FREE_CLIENT 181 
#define  G_CVAR_REGISTER 180 
#define  G_CVAR_SET 179 
#define  G_CVAR_UPDATE 178 
#define  G_CVAR_VARIABLE_INTEGER_VALUE 177 
#define  G_CVAR_VARIABLE_STRING_BUFFER 176 
#define  G_DEBUG_POLYGON_CREATE 175 
#define  G_DEBUG_POLYGON_DELETE 174 
#define  G_DEEPMIND_CALLBACK 173 
#define  G_DROP_CLIENT 172 
#define  G_ENTITIES_IN_BOX 171 
#define  G_ENTITY_CONTACT 170 
#define  G_ENTITY_CONTACTCAPSULE 169 
#define  G_ERROR 168 
#define  G_FS_FCLOSE_FILE 167 
#define  G_FS_FOPEN_FILE 166 
#define  G_FS_GETFILELIST 165 
#define  G_FS_READ 164 
#define  G_FS_SEEK 163 
#define  G_FS_WRITE 162 
#define  G_GET_CONFIGSTRING 161 
#define  G_GET_ENTITY_TOKEN 160 
#define  G_GET_SERVERINFO 159 
#define  G_GET_USERCMD 158 
#define  G_GET_USERINFO 157 
#define  G_IN_PVS 156 
#define  G_IN_PVS_IGNORE_PORTALS 155 
#define  G_LINKENTITY 154 
#define  G_LOCATE_GAME_DATA 153 
#define  G_MILLISECONDS 152 
#define  G_POINT_CONTENTS 151 
#define  G_PRINT 150 
#define  G_REAL_TIME 149 
#define  G_SEND_CONSOLE_COMMAND 148 
#define  G_SEND_SERVER_COMMAND 147 
#define  G_SET_BRUSH_MODEL 146 
#define  G_SET_CONFIGSTRING 145 
#define  G_SET_USERINFO 144 
#define  G_SNAPVECTOR 143 
#define  G_TRACE 142 
#define  G_TRACECAPSULE 141 
#define  G_UNLINKENTITY 140 
 int /*<<< orphan*/  MatrixMultiply (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PerpendicularVector (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Q_SnapVector (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Q_strncpyz (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  SV_AdjustAreaPortalState (int /*<<< orphan*/ *,int) ; 
 int SV_AreaEntities (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int SV_BotAllocateClient () ; 
 int /*<<< orphan*/  SV_BotFreeClient (int) ; 
 int SV_BotGetConsoleMessage (int,int /*<<< orphan*/ *,int) ; 
 int SV_BotGetSnapshotEntity (int,int) ; 
 int SV_BotLibSetup () ; 
 int SV_BotLibShutdown () ; 
 int /*<<< orphan*/  SV_ClientThink (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int SV_EntityContact (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SV_GameDropClient (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_GameSendServerCommand (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_GetConfigstring (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SV_GetServerinfo (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SV_GetUsercmd (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_GetUserinfo (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SV_LinkEntity (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_LocateGameData (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int SV_PointContents (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SV_SetBrushModel (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_SetConfigstring (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_SetUserinfo (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SV_Trace (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/  SV_UnlinkEntity (int /*<<< orphan*/ *) ; 
 int SV_inPVS (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int SV_inPVSIgnorePortals (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int Sys_Milliseconds () ; 
#define  TRAP_ANGLEVECTORS 139 
#define  TRAP_ATAN2 138 
#define  TRAP_CEIL 137 
#define  TRAP_COS 136 
#define  TRAP_FLOOR 135 
#define  TRAP_MATRIXMULTIPLY 134 
#define  TRAP_MEMCPY 133 
#define  TRAP_MEMSET 132 
#define  TRAP_PERPENDICULARVECTOR 131 
#define  TRAP_SIN 130 
#define  TRAP_SQRT 129 
#define  TRAP_STRNCPY 128 
 int /*<<< orphan*/ * VMA (int) ; 
 int /*<<< orphan*/  VMF (int) ; 
 int /*<<< orphan*/  atan2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_7__* botlib_export ; 
 int /*<<< orphan*/  ceil (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cos (int /*<<< orphan*/ ) ; 
 int dmlab_callback (int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  floor (int /*<<< orphan*/ ) ; 
 int qfalse ; 
 int qtrue ; 
 int /*<<< orphan*/  sin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqrt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub10 (int,int /*<<< orphan*/ *) ; 
 int stub100 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub101 (int,int /*<<< orphan*/ *) ; 
 int stub102 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub103 (int,int) ; 
 int /*<<< orphan*/  stub104 (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub105 () ; 
 int /*<<< orphan*/  stub106 () ; 
 int stub107 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub108 (int) ; 
 int /*<<< orphan*/  stub109 (int,int,int) ; 
 int stub11 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub110 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub111 (int,int /*<<< orphan*/ ) ; 
 int stub112 (int) ; 
 int /*<<< orphan*/  stub113 (int) ; 
 int /*<<< orphan*/  stub114 (int) ; 
 int /*<<< orphan*/  stub115 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub116 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ; 
 int stub117 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub118 (int) ; 
 int /*<<< orphan*/  stub119 (int) ; 
 int stub12 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub120 (int /*<<< orphan*/ *,int) ; 
 int stub121 (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub122 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int stub123 () ; 
 int /*<<< orphan*/  stub124 (int) ; 
 int /*<<< orphan*/  stub125 (int,int /*<<< orphan*/ *) ; 
 int stub126 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub127 (int,int,int /*<<< orphan*/ *) ; 
 int stub128 (int,int /*<<< orphan*/ *) ; 
 int stub129 () ; 
 int stub13 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub130 (int) ; 
 int /*<<< orphan*/  stub131 (int) ; 
 int stub132 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub14 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  stub15 (int,int /*<<< orphan*/ *) ; 
 int stub16 () ; 
 int /*<<< orphan*/  stub17 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub18 () ; 
 int stub19 (int /*<<< orphan*/ *) ; 
 int stub2 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub20 (int /*<<< orphan*/ *) ; 
 int stub21 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub22 (int /*<<< orphan*/ *) ; 
 int stub23 (int) ; 
 int stub24 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub25 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub26 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub27 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub28 (int) ; 
 int stub29 (int,int /*<<< orphan*/ *,int,int) ; 
 int stub3 (int /*<<< orphan*/ *) ; 
 int stub30 (int,int) ; 
 int stub31 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int,int,int,int,int,int) ; 
 int stub32 (int /*<<< orphan*/ *) ; 
 int stub33 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  stub34 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub35 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub36 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub37 (int,int) ; 
 int /*<<< orphan*/  stub38 (int) ; 
 int /*<<< orphan*/  stub39 (int) ; 
 int stub4 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub40 (int) ; 
 int /*<<< orphan*/  stub41 (int) ; 
 int /*<<< orphan*/  stub42 (int) ; 
 int /*<<< orphan*/  stub43 (int) ; 
 int /*<<< orphan*/  stub44 (int) ; 
 int /*<<< orphan*/  stub45 (int) ; 
 int /*<<< orphan*/  stub46 (int) ; 
 int /*<<< orphan*/  stub47 (int) ; 
 int /*<<< orphan*/  stub48 (int) ; 
 int /*<<< orphan*/  stub49 (int) ; 
 int stub5 (int) ; 
 int /*<<< orphan*/  stub50 (int,int) ; 
 int /*<<< orphan*/  stub51 (int) ; 
 int /*<<< orphan*/  stub52 (int) ; 
 int /*<<< orphan*/  stub53 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub54 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub55 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub56 (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub57 (int) ; 
 int stub58 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub59 (int) ; 
 int stub6 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub60 (int,int) ; 
 int /*<<< orphan*/  stub61 (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub62 (int,int) ; 
 int stub63 (int,int,int,int) ; 
 int /*<<< orphan*/  stub64 (int,int,int /*<<< orphan*/ *,int) ; 
 int stub65 () ; 
 int /*<<< orphan*/  stub66 (int) ; 
 int /*<<< orphan*/  stub67 (int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub68 (int,int) ; 
 int stub69 (int,int /*<<< orphan*/ *) ; 
 int stub7 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub70 (int) ; 
 int /*<<< orphan*/  stub71 (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub72 (int,int /*<<< orphan*/ *) ; 
 int stub73 (int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub74 (int) ; 
 int /*<<< orphan*/  stub75 (int,int,int) ; 
 int /*<<< orphan*/  stub76 (int,int /*<<< orphan*/ *,int) ; 
 int stub77 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub78 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub79 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ; 
 int stub8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub80 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub81 (int /*<<< orphan*/ *,int) ; 
 int stub82 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub83 (int,int) ; 
 int /*<<< orphan*/  stub84 (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub85 (int) ; 
 int /*<<< orphan*/  stub86 (int) ; 
 int /*<<< orphan*/  stub87 (int,int) ; 
 int /*<<< orphan*/  stub88 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub89 (int) ; 
 int stub9 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub90 (int) ; 
 int /*<<< orphan*/  stub91 (int) ; 
 int /*<<< orphan*/  stub92 (int) ; 
 int /*<<< orphan*/  stub93 (int,int /*<<< orphan*/ *,int) ; 
 int stub94 (int,int /*<<< orphan*/ *) ; 
 int stub95 (int,int /*<<< orphan*/ *) ; 
 int stub96 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub97 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub98 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int stub99 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_6__ sv ; 
 TYPE_5__* sv_maxclients ; 
 TYPE_4__ svs ; 

intptr_t SV_GameSystemCalls( intptr_t *args ) {
	switch( args[0] ) {
	case G_PRINT:
		Com_Printf( "%s", (const char*)VMA(1) );
		return 0;
	case G_ERROR:
		Com_Error( ERR_DROP, "%s", (const char*)VMA(1) );
		return 0;
	case G_MILLISECONDS:
		return Sys_Milliseconds();
	case G_CVAR_REGISTER:
		Cvar_Register( VMA(1), VMA(2), VMA(3), args[4] ); 
		return 0;
	case G_CVAR_UPDATE:
		Cvar_Update( VMA(1) );
		return 0;
	case G_CVAR_SET:
		Cvar_SetSafe( (const char *)VMA(1), (const char *)VMA(2) );
		return 0;
	case G_CVAR_VARIABLE_INTEGER_VALUE:
		return Cvar_VariableIntegerValue( (const char *)VMA(1) );
	case G_CVAR_VARIABLE_STRING_BUFFER:
		Cvar_VariableStringBuffer( VMA(1), VMA(2), args[3] );
		return 0;
	case G_ARGC:
		return Cmd_Argc();
	case G_ARGV:
		Cmd_ArgvBuffer( args[1], VMA(2), args[3] );
		return 0;
	case G_SEND_CONSOLE_COMMAND:
		Cbuf_ExecuteText( args[1], VMA(2) );
		return 0;

	case G_FS_FOPEN_FILE:
		return FS_FOpenFileByMode( VMA(1), VMA(2), args[3] );
	case G_FS_READ:
		FS_Read( VMA(1), args[2], args[3] );
		return 0;
	case G_FS_WRITE:
		FS_Write( VMA(1), args[2], args[3] );
		return 0;
	case G_FS_FCLOSE_FILE:
		FS_FCloseFile( args[1] );
		return 0;
	case G_FS_GETFILELIST:
		return FS_GetFileList( VMA(1), VMA(2), VMA(3), args[4] );
	case G_FS_SEEK:
		return FS_Seek( args[1], args[2], args[3] );

	case G_LOCATE_GAME_DATA:
		SV_LocateGameData( VMA(1), args[2], args[3], VMA(4), args[5] );
		return 0;
	case G_DROP_CLIENT:
		SV_GameDropClient( args[1], VMA(2) );
		return 0;
	case G_SEND_SERVER_COMMAND:
		SV_GameSendServerCommand( args[1], VMA(2) );
		return 0;
	case G_LINKENTITY:
		SV_LinkEntity( VMA(1) );
		return 0;
	case G_UNLINKENTITY:
		SV_UnlinkEntity( VMA(1) );
		return 0;
	case G_ENTITIES_IN_BOX:
		return SV_AreaEntities( VMA(1), VMA(2), VMA(3), args[4] );
	case G_ENTITY_CONTACT:
		return SV_EntityContact( VMA(1), VMA(2), VMA(3), /*int capsule*/ qfalse );
	case G_ENTITY_CONTACTCAPSULE:
		return SV_EntityContact( VMA(1), VMA(2), VMA(3), /*int capsule*/ qtrue );
	case G_TRACE:
		SV_Trace( VMA(1), VMA(2), VMA(3), VMA(4), VMA(5), args[6], args[7], /*int capsule*/ qfalse );
		return 0;
	case G_TRACECAPSULE:
		SV_Trace( VMA(1), VMA(2), VMA(3), VMA(4), VMA(5), args[6], args[7], /*int capsule*/ qtrue );
		return 0;
	case G_POINT_CONTENTS:
		return SV_PointContents( VMA(1), args[2] );
	case G_SET_BRUSH_MODEL:
		SV_SetBrushModel( VMA(1), VMA(2) );
		return 0;
	case G_IN_PVS:
		return SV_inPVS( VMA(1), VMA(2) );
	case G_IN_PVS_IGNORE_PORTALS:
		return SV_inPVSIgnorePortals( VMA(1), VMA(2) );

	case G_SET_CONFIGSTRING:
		SV_SetConfigstring( args[1], VMA(2) );
		return 0;
	case G_GET_CONFIGSTRING:
		SV_GetConfigstring( args[1], VMA(2), args[3] );
		return 0;
	case G_SET_USERINFO:
		SV_SetUserinfo( args[1], VMA(2) );
		return 0;
	case G_GET_USERINFO:
		SV_GetUserinfo( args[1], VMA(2), args[3] );
		return 0;
	case G_GET_SERVERINFO:
		SV_GetServerinfo( VMA(1), args[2] );
		return 0;
	case G_ADJUST_AREA_PORTAL_STATE:
		SV_AdjustAreaPortalState( VMA(1), args[2] );
		return 0;
	case G_AREAS_CONNECTED:
		return CM_AreasConnected( args[1], args[2] );

	case G_BOT_ALLOCATE_CLIENT:
		return SV_BotAllocateClient();
	case G_BOT_FREE_CLIENT:
		SV_BotFreeClient( args[1] );
		return 0;

	case G_GET_USERCMD:
		SV_GetUsercmd( args[1], VMA(2) );
		return 0;
	case G_GET_ENTITY_TOKEN:
		{
			const char	*s;

			s = COM_Parse( &sv.entityParsePoint );
			Q_strncpyz( VMA(1), s, args[2] );
			if ( !sv.entityParsePoint && !s[0] ) {
				return qfalse;
			} else {
				return qtrue;
			}
		}

	case G_DEBUG_POLYGON_CREATE:
		return BotImport_DebugPolygonCreate( args[1], args[2], VMA(3) );
	case G_DEBUG_POLYGON_DELETE:
		BotImport_DebugPolygonDelete( args[1] );
		return 0;
	case G_REAL_TIME:
		return Com_RealTime( VMA(1) );
	case G_SNAPVECTOR:
		Q_SnapVector(VMA(1));
		return 0;

		//====================================

	case BOTLIB_SETUP:
		return SV_BotLibSetup();
	case BOTLIB_SHUTDOWN:
		return SV_BotLibShutdown();
	case BOTLIB_LIBVAR_SET:
		return botlib_export->BotLibVarSet( VMA(1), VMA(2) );
	case BOTLIB_LIBVAR_GET:
		return botlib_export->BotLibVarGet( VMA(1), VMA(2), args[3] );

	case BOTLIB_PC_ADD_GLOBAL_DEFINE:
		return botlib_export->PC_AddGlobalDefine( VMA(1) );
	case BOTLIB_PC_LOAD_SOURCE:
		return botlib_export->PC_LoadSourceHandle( VMA(1) );
	case BOTLIB_PC_FREE_SOURCE:
		return botlib_export->PC_FreeSourceHandle( args[1] );
	case BOTLIB_PC_READ_TOKEN:
		return botlib_export->PC_ReadTokenHandle( args[1], VMA(2) );
	case BOTLIB_PC_SOURCE_FILE_AND_LINE:
		return botlib_export->PC_SourceFileAndLine( args[1], VMA(2), VMA(3) );

	case BOTLIB_START_FRAME:
		return botlib_export->BotLibStartFrame( VMF(1) );
	case BOTLIB_LOAD_MAP:
		return botlib_export->BotLibLoadMap( VMA(1) );
	case BOTLIB_UPDATENTITY:
		return botlib_export->BotLibUpdateEntity( args[1], VMA(2) );
	case BOTLIB_TEST:
		return botlib_export->Test( args[1], VMA(2), VMA(3), VMA(4) );

	case BOTLIB_GET_SNAPSHOT_ENTITY:
		return SV_BotGetSnapshotEntity( args[1], args[2] );
	case BOTLIB_GET_CONSOLE_MESSAGE:
		return SV_BotGetConsoleMessage( args[1], VMA(2), args[3] );
	case BOTLIB_USER_COMMAND:
		{
			int clientNum = args[1];

			if ( clientNum >= 0 && clientNum < sv_maxclients->integer ) {
				SV_ClientThink( &svs.clients[clientNum], VMA(2) );
			}
		}
		return 0;

	case BOTLIB_AAS_BBOX_AREAS:
		return botlib_export->aas.AAS_BBoxAreas( VMA(1), VMA(2), VMA(3), args[4] );
	case BOTLIB_AAS_AREA_INFO:
		return botlib_export->aas.AAS_AreaInfo( args[1], VMA(2) );
	case BOTLIB_AAS_ALTERNATIVE_ROUTE_GOAL:
		return botlib_export->aas.AAS_AlternativeRouteGoals( VMA(1), args[2], VMA(3), args[4], args[5], VMA(6), args[7], args[8] );
	case BOTLIB_AAS_ENTITY_INFO:
		botlib_export->aas.AAS_EntityInfo( args[1], VMA(2) );
		return 0;

	case BOTLIB_AAS_INITIALIZED:
		return botlib_export->aas.AAS_Initialized();
	case BOTLIB_AAS_PRESENCE_TYPE_BOUNDING_BOX:
		botlib_export->aas.AAS_PresenceTypeBoundingBox( args[1], VMA(2), VMA(3) );
		return 0;
	case BOTLIB_AAS_TIME:
		return FloatAsInt( botlib_export->aas.AAS_Time() );

	case BOTLIB_AAS_POINT_AREA_NUM:
		return botlib_export->aas.AAS_PointAreaNum( VMA(1) );
	case BOTLIB_AAS_POINT_REACHABILITY_AREA_INDEX:
		return botlib_export->aas.AAS_PointReachabilityAreaIndex( VMA(1) );
	case BOTLIB_AAS_TRACE_AREAS:
		return botlib_export->aas.AAS_TraceAreas( VMA(1), VMA(2), VMA(3), VMA(4), args[5] );

	case BOTLIB_AAS_POINT_CONTENTS:
		return botlib_export->aas.AAS_PointContents( VMA(1) );
	case BOTLIB_AAS_NEXT_BSP_ENTITY:
		return botlib_export->aas.AAS_NextBSPEntity( args[1] );
	case BOTLIB_AAS_VALUE_FOR_BSP_EPAIR_KEY:
		return botlib_export->aas.AAS_ValueForBSPEpairKey( args[1], VMA(2), VMA(3), args[4] );
	case BOTLIB_AAS_VECTOR_FOR_BSP_EPAIR_KEY:
		return botlib_export->aas.AAS_VectorForBSPEpairKey( args[1], VMA(2), VMA(3) );
	case BOTLIB_AAS_FLOAT_FOR_BSP_EPAIR_KEY:
		return botlib_export->aas.AAS_FloatForBSPEpairKey( args[1], VMA(2), VMA(3) );
	case BOTLIB_AAS_INT_FOR_BSP_EPAIR_KEY:
		return botlib_export->aas.AAS_IntForBSPEpairKey( args[1], VMA(2), VMA(3) );

	case BOTLIB_AAS_AREA_REACHABILITY:
		return botlib_export->aas.AAS_AreaReachability( args[1] );

	case BOTLIB_AAS_AREA_TRAVEL_TIME_TO_GOAL_AREA:
		return botlib_export->aas.AAS_AreaTravelTimeToGoalArea( args[1], VMA(2), args[3], args[4] );
	case BOTLIB_AAS_ENABLE_ROUTING_AREA:
		return botlib_export->aas.AAS_EnableRoutingArea( args[1], args[2] );
	case BOTLIB_AAS_PREDICT_ROUTE:
		return botlib_export->aas.AAS_PredictRoute( VMA(1), args[2], VMA(3), args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11] );

	case BOTLIB_AAS_SWIMMING:
		return botlib_export->aas.AAS_Swimming( VMA(1) );
	case BOTLIB_AAS_PREDICT_CLIENT_MOVEMENT:
		return botlib_export->aas.AAS_PredictClientMovement( VMA(1), args[2], VMA(3), args[4], args[5],
			VMA(6), VMA(7), args[8], args[9], VMF(10), args[11], args[12], args[13] );

	case BOTLIB_EA_SAY:
		botlib_export->ea.EA_Say( args[1], VMA(2) );
		return 0;
	case BOTLIB_EA_SAY_TEAM:
		botlib_export->ea.EA_SayTeam( args[1], VMA(2) );
		return 0;
	case BOTLIB_EA_COMMAND:
		botlib_export->ea.EA_Command( args[1], VMA(2) );
		return 0;

	case BOTLIB_EA_ACTION:
		botlib_export->ea.EA_Action( args[1], args[2] );
		return 0;
	case BOTLIB_EA_GESTURE:
		botlib_export->ea.EA_Gesture( args[1] );
		return 0;
	case BOTLIB_EA_TALK:
		botlib_export->ea.EA_Talk( args[1] );
		return 0;
	case BOTLIB_EA_ATTACK:
		botlib_export->ea.EA_Attack( args[1] );
		return 0;
	case BOTLIB_EA_USE:
		botlib_export->ea.EA_Use( args[1] );
		return 0;
	case BOTLIB_EA_RESPAWN:
		botlib_export->ea.EA_Respawn( args[1] );
		return 0;
	case BOTLIB_EA_CROUCH:
		botlib_export->ea.EA_Crouch( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_UP:
		botlib_export->ea.EA_MoveUp( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_DOWN:
		botlib_export->ea.EA_MoveDown( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_FORWARD:
		botlib_export->ea.EA_MoveForward( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_BACK:
		botlib_export->ea.EA_MoveBack( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_LEFT:
		botlib_export->ea.EA_MoveLeft( args[1] );
		return 0;
	case BOTLIB_EA_MOVE_RIGHT:
		botlib_export->ea.EA_MoveRight( args[1] );
		return 0;

	case BOTLIB_EA_SELECT_WEAPON:
		botlib_export->ea.EA_SelectWeapon( args[1], args[2] );
		return 0;
	case BOTLIB_EA_JUMP:
		botlib_export->ea.EA_Jump( args[1] );
		return 0;
	case BOTLIB_EA_DELAYED_JUMP:
		botlib_export->ea.EA_DelayedJump( args[1] );
		return 0;
	case BOTLIB_EA_MOVE:
		botlib_export->ea.EA_Move( args[1], VMA(2), VMF(3) );
		return 0;
	case BOTLIB_EA_VIEW:
		botlib_export->ea.EA_View( args[1], VMA(2) );
		return 0;

	case BOTLIB_EA_END_REGULAR:
		botlib_export->ea.EA_EndRegular( args[1], VMF(2) );
		return 0;
	case BOTLIB_EA_GET_INPUT:
		botlib_export->ea.EA_GetInput( args[1], VMF(2), VMA(3) );
		return 0;
	case BOTLIB_EA_RESET_INPUT:
		botlib_export->ea.EA_ResetInput( args[1] );
		return 0;

	case BOTLIB_AI_LOAD_CHARACTER:
		return botlib_export->ai.BotLoadCharacter( VMA(1), VMF(2) );
	case BOTLIB_AI_FREE_CHARACTER:
		botlib_export->ai.BotFreeCharacter( args[1] );
		return 0;
	case BOTLIB_AI_CHARACTERISTIC_FLOAT:
		return FloatAsInt( botlib_export->ai.Characteristic_Float( args[1], args[2] ) );
	case BOTLIB_AI_CHARACTERISTIC_BFLOAT:
		return FloatAsInt( botlib_export->ai.Characteristic_BFloat( args[1], args[2], VMF(3), VMF(4) ) );
	case BOTLIB_AI_CHARACTERISTIC_INTEGER:
		return botlib_export->ai.Characteristic_Integer( args[1], args[2] );
	case BOTLIB_AI_CHARACTERISTIC_BINTEGER:
		return botlib_export->ai.Characteristic_BInteger( args[1], args[2], args[3], args[4] );
	case BOTLIB_AI_CHARACTERISTIC_STRING:
		botlib_export->ai.Characteristic_String( args[1], args[2], VMA(3), args[4] );
		return 0;

	case BOTLIB_AI_ALLOC_CHAT_STATE:
		return botlib_export->ai.BotAllocChatState();
	case BOTLIB_AI_FREE_CHAT_STATE:
		botlib_export->ai.BotFreeChatState( args[1] );
		return 0;
	case BOTLIB_AI_QUEUE_CONSOLE_MESSAGE:
		botlib_export->ai.BotQueueConsoleMessage( args[1], args[2], VMA(3) );
		return 0;
	case BOTLIB_AI_REMOVE_CONSOLE_MESSAGE:
		botlib_export->ai.BotRemoveConsoleMessage( args[1], args[2] );
		return 0;
	case BOTLIB_AI_NEXT_CONSOLE_MESSAGE:
		return botlib_export->ai.BotNextConsoleMessage( args[1], VMA(2) );
	case BOTLIB_AI_NUM_CONSOLE_MESSAGE:
		return botlib_export->ai.BotNumConsoleMessages( args[1] );
	case BOTLIB_AI_INITIAL_CHAT:
		botlib_export->ai.BotInitialChat( args[1], VMA(2), args[3], VMA(4), VMA(5), VMA(6), VMA(7), VMA(8), VMA(9), VMA(10), VMA(11) );
		return 0;
	case BOTLIB_AI_NUM_INITIAL_CHATS:
		return botlib_export->ai.BotNumInitialChats( args[1], VMA(2) );
	case BOTLIB_AI_REPLY_CHAT:
		return botlib_export->ai.BotReplyChat( args[1], VMA(2), args[3], args[4], VMA(5), VMA(6), VMA(7), VMA(8), VMA(9), VMA(10), VMA(11), VMA(12) );
	case BOTLIB_AI_CHAT_LENGTH:
		return botlib_export->ai.BotChatLength( args[1] );
	case BOTLIB_AI_ENTER_CHAT:
		botlib_export->ai.BotEnterChat( args[1], args[2], args[3] );
		return 0;
	case BOTLIB_AI_GET_CHAT_MESSAGE:
		botlib_export->ai.BotGetChatMessage( args[1], VMA(2), args[3] );
		return 0;
	case BOTLIB_AI_STRING_CONTAINS:
		return botlib_export->ai.StringContains( VMA(1), VMA(2), args[3] );
	case BOTLIB_AI_FIND_MATCH:
		return botlib_export->ai.BotFindMatch( VMA(1), VMA(2), args[3] );
	case BOTLIB_AI_MATCH_VARIABLE:
		botlib_export->ai.BotMatchVariable( VMA(1), args[2], VMA(3), args[4] );
		return 0;
	case BOTLIB_AI_UNIFY_WHITE_SPACES:
		botlib_export->ai.UnifyWhiteSpaces( VMA(1) );
		return 0;
	case BOTLIB_AI_REPLACE_SYNONYMS:
		botlib_export->ai.BotReplaceSynonyms( VMA(1), args[2] );
		return 0;
	case BOTLIB_AI_LOAD_CHAT_FILE:
		return botlib_export->ai.BotLoadChatFile( args[1], VMA(2), VMA(3) );
	case BOTLIB_AI_SET_CHAT_GENDER:
		botlib_export->ai.BotSetChatGender( args[1], args[2] );
		return 0;
	case BOTLIB_AI_SET_CHAT_NAME:
		botlib_export->ai.BotSetChatName( args[1], VMA(2), args[3] );
		return 0;

	case BOTLIB_AI_RESET_GOAL_STATE:
		botlib_export->ai.BotResetGoalState( args[1] );
		return 0;
	case BOTLIB_AI_RESET_AVOID_GOALS:
		botlib_export->ai.BotResetAvoidGoals( args[1] );
		return 0;
	case BOTLIB_AI_REMOVE_FROM_AVOID_GOALS:
		botlib_export->ai.BotRemoveFromAvoidGoals( args[1], args[2] );
		return 0;
	case BOTLIB_AI_PUSH_GOAL:
		botlib_export->ai.BotPushGoal( args[1], VMA(2) );
		return 0;
	case BOTLIB_AI_POP_GOAL:
		botlib_export->ai.BotPopGoal( args[1] );
		return 0;
	case BOTLIB_AI_EMPTY_GOAL_STACK:
		botlib_export->ai.BotEmptyGoalStack( args[1] );
		return 0;
	case BOTLIB_AI_DUMP_AVOID_GOALS:
		botlib_export->ai.BotDumpAvoidGoals( args[1] );
		return 0;
	case BOTLIB_AI_DUMP_GOAL_STACK:
		botlib_export->ai.BotDumpGoalStack( args[1] );
		return 0;
	case BOTLIB_AI_GOAL_NAME:
		botlib_export->ai.BotGoalName( args[1], VMA(2), args[3] );
		return 0;
	case BOTLIB_AI_GET_TOP_GOAL:
		return botlib_export->ai.BotGetTopGoal( args[1], VMA(2) );
	case BOTLIB_AI_GET_SECOND_GOAL:
		return botlib_export->ai.BotGetSecondGoal( args[1], VMA(2) );
	case BOTLIB_AI_CHOOSE_LTG_ITEM:
		return botlib_export->ai.BotChooseLTGItem( args[1], VMA(2), VMA(3), args[4] );
	case BOTLIB_AI_CHOOSE_NBG_ITEM:
		return botlib_export->ai.BotChooseNBGItem( args[1], VMA(2), VMA(3), args[4], VMA(5), VMF(6) );
	case BOTLIB_AI_TOUCHING_GOAL:
		return botlib_export->ai.BotTouchingGoal( VMA(1), VMA(2) );
	case BOTLIB_AI_ITEM_GOAL_IN_VIS_BUT_NOT_VISIBLE:
		return botlib_export->ai.BotItemGoalInVisButNotVisible( args[1], VMA(2), VMA(3), VMA(4) );
	case BOTLIB_AI_GET_LEVEL_ITEM_GOAL:
		return botlib_export->ai.BotGetLevelItemGoal( args[1], VMA(2), VMA(3) );
	case BOTLIB_AI_GET_NEXT_CAMP_SPOT_GOAL:
		return botlib_export->ai.BotGetNextCampSpotGoal( args[1], VMA(2) );
	case BOTLIB_AI_GET_MAP_LOCATION_GOAL:
		return botlib_export->ai.BotGetMapLocationGoal( VMA(1), VMA(2) );
	case BOTLIB_AI_AVOID_GOAL_TIME:
		return FloatAsInt( botlib_export->ai.BotAvoidGoalTime( args[1], args[2] ) );
	case BOTLIB_AI_SET_AVOID_GOAL_TIME:
		botlib_export->ai.BotSetAvoidGoalTime( args[1], args[2], VMF(3));
		return 0;
	case BOTLIB_AI_INIT_LEVEL_ITEMS:
		botlib_export->ai.BotInitLevelItems();
		return 0;
	case BOTLIB_AI_UPDATE_ENTITY_ITEMS:
		botlib_export->ai.BotUpdateEntityItems();
		return 0;
	case BOTLIB_AI_LOAD_ITEM_WEIGHTS:
		return botlib_export->ai.BotLoadItemWeights( args[1], VMA(2) );
	case BOTLIB_AI_FREE_ITEM_WEIGHTS:
		botlib_export->ai.BotFreeItemWeights( args[1] );
		return 0;
	case BOTLIB_AI_INTERBREED_GOAL_FUZZY_LOGIC:
		botlib_export->ai.BotInterbreedGoalFuzzyLogic( args[1], args[2], args[3] );
		return 0;
	case BOTLIB_AI_SAVE_GOAL_FUZZY_LOGIC:
		botlib_export->ai.BotSaveGoalFuzzyLogic( args[1], VMA(2) );
		return 0;
	case BOTLIB_AI_MUTATE_GOAL_FUZZY_LOGIC:
		botlib_export->ai.BotMutateGoalFuzzyLogic( args[1], VMF(2) );
		return 0;
	case BOTLIB_AI_ALLOC_GOAL_STATE:
		return botlib_export->ai.BotAllocGoalState( args[1] );
	case BOTLIB_AI_FREE_GOAL_STATE:
		botlib_export->ai.BotFreeGoalState( args[1] );
		return 0;

	case BOTLIB_AI_RESET_MOVE_STATE:
		botlib_export->ai.BotResetMoveState( args[1] );
		return 0;
	case BOTLIB_AI_ADD_AVOID_SPOT:
		botlib_export->ai.BotAddAvoidSpot( args[1], VMA(2), VMF(3), args[4] );
		return 0;
	case BOTLIB_AI_MOVE_TO_GOAL:
		botlib_export->ai.BotMoveToGoal( VMA(1), args[2], VMA(3), args[4] );
		return 0;
	case BOTLIB_AI_MOVE_IN_DIRECTION:
		return botlib_export->ai.BotMoveInDirection( args[1], VMA(2), VMF(3), args[4] );
	case BOTLIB_AI_RESET_AVOID_REACH:
		botlib_export->ai.BotResetAvoidReach( args[1] );
		return 0;
	case BOTLIB_AI_RESET_LAST_AVOID_REACH:
		botlib_export->ai.BotResetLastAvoidReach( args[1] );
		return 0;
	case BOTLIB_AI_REACHABILITY_AREA:
		return botlib_export->ai.BotReachabilityArea( VMA(1), args[2] );
	case BOTLIB_AI_MOVEMENT_VIEW_TARGET:
		return botlib_export->ai.BotMovementViewTarget( args[1], VMA(2), args[3], VMF(4), VMA(5) );
	case BOTLIB_AI_PREDICT_VISIBLE_POSITION:
		return botlib_export->ai.BotPredictVisiblePosition( VMA(1), args[2], VMA(3), args[4], VMA(5) );
	case BOTLIB_AI_ALLOC_MOVE_STATE:
		return botlib_export->ai.BotAllocMoveState();
	case BOTLIB_AI_FREE_MOVE_STATE:
		botlib_export->ai.BotFreeMoveState( args[1] );
		return 0;
	case BOTLIB_AI_INIT_MOVE_STATE:
		botlib_export->ai.BotInitMoveState( args[1], VMA(2) );
		return 0;

	case BOTLIB_AI_CHOOSE_BEST_FIGHT_WEAPON:
		return botlib_export->ai.BotChooseBestFightWeapon( args[1], VMA(2) );
	case BOTLIB_AI_GET_WEAPON_INFO:
		botlib_export->ai.BotGetWeaponInfo( args[1], args[2], VMA(3) );
		return 0;
	case BOTLIB_AI_LOAD_WEAPON_WEIGHTS:
		return botlib_export->ai.BotLoadWeaponWeights( args[1], VMA(2) );
	case BOTLIB_AI_ALLOC_WEAPON_STATE:
		return botlib_export->ai.BotAllocWeaponState();
	case BOTLIB_AI_FREE_WEAPON_STATE:
		botlib_export->ai.BotFreeWeaponState( args[1] );
		return 0;
	case BOTLIB_AI_RESET_WEAPON_STATE:
		botlib_export->ai.BotResetWeaponState( args[1] );
		return 0;

	case BOTLIB_AI_GENETIC_PARENTS_AND_CHILD_SELECTION:
		return botlib_export->ai.GeneticParentsAndChildSelection(args[1], VMA(2), VMA(3), VMA(4), VMA(5));

	case TRAP_MEMSET:
		Com_Memset( VMA(1), args[2], args[3] );
		return 0;

	case TRAP_MEMCPY:
		Com_Memcpy( VMA(1), VMA(2), args[3] );
		return 0;

	case TRAP_STRNCPY:
		strncpy( VMA(1), VMA(2), args[3] );
		return args[1];

	case TRAP_SIN:
		return FloatAsInt( sin( VMF(1) ) );

	case TRAP_COS:
		return FloatAsInt( cos( VMF(1) ) );

	case TRAP_ATAN2:
		return FloatAsInt( atan2( VMF(1), VMF(2) ) );

	case TRAP_SQRT:
		return FloatAsInt( sqrt( VMF(1) ) );

	case TRAP_MATRIXMULTIPLY:
		MatrixMultiply( VMA(1), VMA(2), VMA(3) );
		return 0;

	case TRAP_ANGLEVECTORS:
		AngleVectors( VMA(1), VMA(2), VMA(3), VMA(4) );
		return 0;

	case TRAP_PERPENDICULARVECTOR:
		PerpendicularVector( VMA(1), VMA(2) );
		return 0;

	case TRAP_FLOOR:
		return FloatAsInt( floor( VMF(1) ) );

	case TRAP_CEIL:
		return FloatAsInt( ceil( VMF(1) ) );

	case G_DEEPMIND_CALLBACK:
		return dmlab_callback( args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13] );

	default:
		Com_Error( ERR_DROP, "Bad game system trap: %ld", (long int) args[0] );
	}
	return 0;
}