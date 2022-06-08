#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_74__   TYPE_9__ ;
typedef  struct TYPE_73__   TYPE_8__ ;
typedef  struct TYPE_72__   TYPE_7__ ;
typedef  struct TYPE_71__   TYPE_6__ ;
typedef  struct TYPE_70__   TYPE_5__ ;
typedef  struct TYPE_69__   TYPE_4__ ;
typedef  struct TYPE_68__   TYPE_3__ ;
typedef  struct TYPE_67__   TYPE_37__ ;
typedef  struct TYPE_66__   TYPE_36__ ;
typedef  struct TYPE_65__   TYPE_35__ ;
typedef  struct TYPE_64__   TYPE_34__ ;
typedef  struct TYPE_63__   TYPE_33__ ;
typedef  struct TYPE_62__   TYPE_32__ ;
typedef  struct TYPE_61__   TYPE_31__ ;
typedef  struct TYPE_60__   TYPE_30__ ;
typedef  struct TYPE_59__   TYPE_2__ ;
typedef  struct TYPE_58__   TYPE_29__ ;
typedef  struct TYPE_57__   TYPE_28__ ;
typedef  struct TYPE_56__   TYPE_27__ ;
typedef  struct TYPE_55__   TYPE_26__ ;
typedef  struct TYPE_54__   TYPE_25__ ;
typedef  struct TYPE_53__   TYPE_24__ ;
typedef  struct TYPE_52__   TYPE_23__ ;
typedef  struct TYPE_51__   TYPE_22__ ;
typedef  struct TYPE_50__   TYPE_21__ ;
typedef  struct TYPE_49__   TYPE_20__ ;
typedef  struct TYPE_48__   TYPE_1__ ;
typedef  struct TYPE_47__   TYPE_19__ ;
typedef  struct TYPE_46__   TYPE_18__ ;
typedef  struct TYPE_45__   TYPE_17__ ;
typedef  struct TYPE_44__   TYPE_16__ ;
typedef  struct TYPE_43__   TYPE_15__ ;
typedef  struct TYPE_42__   TYPE_14__ ;
typedef  struct TYPE_41__   TYPE_13__ ;
typedef  struct TYPE_40__   TYPE_12__ ;
typedef  struct TYPE_39__   TYPE_11__ ;
typedef  struct TYPE_38__   TYPE_10__ ;

/* Type definitions */
struct TYPE_62__ {int len; } ;
struct TYPE_61__ {unsigned char* list; } ;
union codeview_reftype {TYPE_32__ generic; TYPE_31__ fieldlist; } ;
struct TYPE_63__ {int id; } ;
struct TYPE_60__ {unsigned int ref; } ;
struct TYPE_58__ {unsigned int ref; } ;
struct TYPE_57__ {int attribute; char const* name; } ;
struct TYPE_56__ {char const* name; } ;
struct TYPE_54__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_55__ {int attribute; TYPE_25__ p_name; } ;
struct TYPE_52__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_53__ {TYPE_23__ p_name; } ;
struct TYPE_50__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_51__ {int attribute; TYPE_21__ p_name; } ;
struct TYPE_47__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_49__ {TYPE_19__ p_name; } ;
struct TYPE_46__ {char const* name; } ;
struct TYPE_44__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_45__ {TYPE_16__ p_name; } ;
struct TYPE_42__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_43__ {TYPE_14__ p_name; } ;
struct TYPE_41__ {char const* name; } ;
struct TYPE_39__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_40__ {TYPE_11__ p_name; } ;
struct TYPE_74__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_38__ {TYPE_9__ p_name; } ;
struct TYPE_73__ {char const* name; } ;
struct TYPE_71__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_72__ {TYPE_6__ p_name; } ;
struct TYPE_69__ {int /*<<< orphan*/  namelen; } ;
struct TYPE_70__ {TYPE_4__ p_name; } ;
struct TYPE_68__ {unsigned short const offset; int /*<<< orphan*/  type; } ;
struct TYPE_59__ {unsigned short const offset; int /*<<< orphan*/  type; } ;
struct TYPE_48__ {unsigned short const offset; int /*<<< orphan*/  type; } ;
struct TYPE_67__ {unsigned short const vbpoff; } ;
struct TYPE_66__ {unsigned short const vbpoff; } ;
struct TYPE_65__ {unsigned short const offset; } ;
struct TYPE_64__ {unsigned short const offset; } ;
union codeview_fieldtype {TYPE_33__ generic; TYPE_30__ index_v2; TYPE_29__ index_v1; TYPE_28__ onemethod_v3; TYPE_27__ onemethod_virt_v3; TYPE_26__ onemethod_v2; TYPE_24__ onemethod_virt_v2; TYPE_22__ onemethod_v1; TYPE_20__ onemethod_virt_v1; TYPE_18__ nesttype_v3; TYPE_17__ nesttype_v2; TYPE_15__ nesttype_v1; TYPE_13__ method_v3; TYPE_12__ method_v2; TYPE_10__ method_v1; TYPE_8__ stmember_v3; TYPE_7__ stmember_v2; TYPE_5__ stmember_v1; TYPE_3__ member_v3; TYPE_2__ member_v2; TYPE_1__ member_v1; TYPE_37__ vbclass_v2; TYPE_36__ vbclass_v1; TYPE_35__ bclass_v2; TYPE_34__ bclass_v1; } ;
struct symt_udt {int dummy; } ;
struct p_string {int /*<<< orphan*/  namelen; } ;
struct codeview_type_parse {int dummy; } ;
typedef  unsigned char BYTE ;

/* Variables and functions */
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int) ; 
#define  LF_BCLASS_V1 152 
#define  LF_BCLASS_V2 151 
#define  LF_INDEX_V1 150 
#define  LF_INDEX_V2 149 
#define  LF_IVBCLASS_V1 148 
#define  LF_IVBCLASS_V2 147 
#define  LF_MEMBER_V1 146 
#define  LF_MEMBER_V2 145 
#define  LF_MEMBER_V3 144 
#define  LF_METHOD_V1 143 
#define  LF_METHOD_V2 142 
#define  LF_METHOD_V3 141 
#define  LF_NESTTYPE_V1 140 
#define  LF_NESTTYPE_V2 139 
#define  LF_NESTTYPE_V3 138 
#define  LF_ONEMETHOD_V1 137 
#define  LF_ONEMETHOD_V2 136 
#define  LF_ONEMETHOD_V3 135 
#define  LF_STMEMBER_V1 134 
#define  LF_STMEMBER_V2 133 
#define  LF_STMEMBER_V3 132 
#define  LF_VBCLASS_V1 131 
#define  LF_VBCLASS_V2 130 
#define  LF_VFUNCTAB_V1 129 
#define  LF_VFUNCTAB_V2 128 
 int TRUE ; 
 int /*<<< orphan*/  codeview_add_udt_element (struct codeview_type_parse*,struct symt_udt*,char const*,int,int /*<<< orphan*/ ) ; 
 union codeview_reftype* codeview_jump_to_type (struct codeview_type_parse*,unsigned int) ; 
 int numeric_leaf (int*,unsigned short const*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 char const* terminate_string (struct p_string const*) ; 

__attribute__((used)) static int codeview_add_type_struct_field_list(struct codeview_type_parse* ctp,
                                               struct symt_udt* symt,
                                               unsigned fieldlistno)
{
    const unsigned char*        ptr;
    const unsigned char*        last;
    int                         value, leaf_len;
    const struct p_string*      p_name;
    const char*                 c_name;
    const union codeview_reftype*type_ref;
    const union codeview_fieldtype* type;

    if (!fieldlistno) return TRUE;
    type_ref = codeview_jump_to_type(ctp, fieldlistno);
    ptr = type_ref->fieldlist.list;
    last = (const BYTE*)type_ref + type_ref->generic.len + 2;

    while (ptr < last)
    {
        if (*ptr >= 0xf0)       /* LF_PAD... */
        {
            ptr += *ptr & 0x0f;
            continue;
        }

        type = (const union codeview_fieldtype*)ptr;

        switch (type->generic.id)
        {
        case LF_BCLASS_V1:
            leaf_len = numeric_leaf(&value, &type->bclass_v1.offset);

            /* FIXME: ignored for now */

            ptr += 2 + 2 + 2 + leaf_len;
            break;

        case LF_BCLASS_V2:
            leaf_len = numeric_leaf(&value, &type->bclass_v2.offset);

            /* FIXME: ignored for now */

            ptr += 2 + 2 + 4 + leaf_len;
            break;

        case LF_VBCLASS_V1:
        case LF_IVBCLASS_V1:
            {
                const unsigned short int* p_vboff;
                int vpoff, vplen;
                leaf_len = numeric_leaf(&value, &type->vbclass_v1.vbpoff);
                p_vboff = (const unsigned short int*)((const char*)&type->vbclass_v1.vbpoff + leaf_len);
                vplen = numeric_leaf(&vpoff, p_vboff);

                /* FIXME: ignored for now */

                ptr += 2 + 2 + 2 + 2 + leaf_len + vplen;
            }
            break;

        case LF_VBCLASS_V2:
        case LF_IVBCLASS_V2:
            {
                const unsigned short int* p_vboff;
                int vpoff, vplen;
                leaf_len = numeric_leaf(&value, &type->vbclass_v2.vbpoff);
                p_vboff = (const unsigned short int*)((const char*)&type->vbclass_v2.vbpoff + leaf_len);
                vplen = numeric_leaf(&vpoff, p_vboff);

                /* FIXME: ignored for now */

                ptr += 2 + 2 + 4 + 4 + leaf_len + vplen;
            }
            break;

        case LF_MEMBER_V1:
            leaf_len = numeric_leaf(&value, &type->member_v1.offset);
            p_name = (const struct p_string*)((const char*)&type->member_v1.offset + leaf_len);

            codeview_add_udt_element(ctp, symt, terminate_string(p_name), value, 
                                     type->member_v1.type);

            ptr += 2 + 2 + 2 + leaf_len + (1 + p_name->namelen);
            break;

        case LF_MEMBER_V2:
            leaf_len = numeric_leaf(&value, &type->member_v2.offset);
            p_name = (const struct p_string*)((const unsigned char*)&type->member_v2.offset + leaf_len);

            codeview_add_udt_element(ctp, symt, terminate_string(p_name), value, 
                                     type->member_v2.type);

            ptr += 2 + 2 + 4 + leaf_len + (1 + p_name->namelen);
            break;

        case LF_MEMBER_V3:
            leaf_len = numeric_leaf(&value, &type->member_v3.offset);
            c_name = (const char*)&type->member_v3.offset + leaf_len;

            codeview_add_udt_element(ctp, symt, c_name, value, type->member_v3.type);

            ptr += 2 + 2 + 4 + leaf_len + (strlen(c_name) + 1);
            break;

        case LF_STMEMBER_V1:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 2 + (1 + type->stmember_v1.p_name.namelen);
            break;

        case LF_STMEMBER_V2:
            /* FIXME: ignored for now */
            ptr += 2 + 4 + 2 + (1 + type->stmember_v2.p_name.namelen);
            break;

        case LF_STMEMBER_V3:
            /* FIXME: ignored for now */
            ptr += 2 + 4 + 2 + (strlen(type->stmember_v3.name) + 1);
            break;

        case LF_METHOD_V1:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 2 + (1 + type->method_v1.p_name.namelen);
            break;

        case LF_METHOD_V2:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 4 + (1 + type->method_v2.p_name.namelen);
            break;

        case LF_METHOD_V3:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 4 + (strlen(type->method_v3.name) + 1);
            break;

        case LF_NESTTYPE_V1:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + (1 + type->nesttype_v1.p_name.namelen);
            break;

        case LF_NESTTYPE_V2:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 4 + (1 + type->nesttype_v2.p_name.namelen);
            break;

        case LF_NESTTYPE_V3:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 4 + (strlen(type->nesttype_v3.name) + 1);
            break;

        case LF_VFUNCTAB_V1:
            /* FIXME: ignored for now */
            ptr += 2 + 2;
            break;

        case LF_VFUNCTAB_V2:
            /* FIXME: ignored for now */
            ptr += 2 + 2 + 4;
            break;

        case LF_ONEMETHOD_V1:
            /* FIXME: ignored for now */
            switch ((type->onemethod_v1.attribute >> 2) & 7)
            {
            case 4: case 6: /* (pure) introducing virtual method */
                ptr += 2 + 2 + 2 + 4 + (1 + type->onemethod_virt_v1.p_name.namelen);
                break;

            default:
                ptr += 2 + 2 + 2 + (1 + type->onemethod_v1.p_name.namelen);
                break;
            }
            break;

        case LF_ONEMETHOD_V2:
            /* FIXME: ignored for now */
            switch ((type->onemethod_v2.attribute >> 2) & 7)
            {
            case 4: case 6: /* (pure) introducing virtual method */
                ptr += 2 + 2 + 4 + 4 + (1 + type->onemethod_virt_v2.p_name.namelen);
                break;

            default:
                ptr += 2 + 2 + 4 + (1 + type->onemethod_v2.p_name.namelen);
                break;
            }
            break;

        case LF_ONEMETHOD_V3:
            /* FIXME: ignored for now */
            switch ((type->onemethod_v3.attribute >> 2) & 7)
            {
            case 4: case 6: /* (pure) introducing virtual method */
                ptr += 2 + 2 + 4 + 4 + (strlen(type->onemethod_virt_v3.name) + 1);
                break;

            default:
                ptr += 2 + 2 + 4 + (strlen(type->onemethod_v3.name) + 1);
                break;
            }
            break;

        case LF_INDEX_V1:
            if (!codeview_add_type_struct_field_list(ctp, symt, type->index_v1.ref))
                return FALSE;
            ptr += 2 + 2;
            break;

        case LF_INDEX_V2:
            if (!codeview_add_type_struct_field_list(ctp, symt, type->index_v2.ref))
                return FALSE;
            ptr += 2 + 2 + 4;
            break;

        default:
            FIXME("Unsupported type %04x in STRUCT field list\n", type->generic.id);
            return FALSE;
        }
    }

    return TRUE;
}