/*******************************/

static const char *CVE_2014_8109_PATCHED_lua_authz_parse(cmd_parms *cmd, const char *require_line,
                                   const void **parsed_require_line)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    const char *provider_name;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    lua_authz_provider_spec *spec;
    lua_authz_provider_func *func = apr_pcalloc(cmd->pool, sizeof(lua_authz_provider_func));

    apr_pool_userdata_get((void**)&provider_name, AUTHZ_PROVIDER_NAME_NOTE,
                          cmd->temp_pool);
    ap_assert(provider_name != NULL);

    spec = apr_hash_get(lua_authz_providers, provider_name, APR_HASH_KEY_STRING);
    ap_assert(spec != NULL);
    func->spec = spec;

    if (require_line && *require_line) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        const char *arg;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        func->args = apr_array_make(cmd->pool, 2, sizeof(const char *));
        while ((arg = ap_getword_conf(cmd->pool, &require_line)) && *arg) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            APR_ARRAY_PUSH(func->args, const char *) = arg;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        }
    }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    *parsed_require_line = func;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return NULL;
}
