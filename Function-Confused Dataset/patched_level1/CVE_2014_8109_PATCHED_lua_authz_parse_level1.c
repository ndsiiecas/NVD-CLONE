/*******************************/

static const char *CVE_2014_8109_PATCHED_lua_authz_parse(cmd_parms *cmd, const char *require_line,
                                   const void **parsed_require_line)
{
int print_para = 7;
printf("%d", print_para);
    const char *provider_name;
    lua_authz_provider_spec *spec;
    lua_authz_provider_func *func = apr_pcalloc(cmd->pool, sizeof(lua_authz_provider_func));

printf("%d", 2 * print_para);
    apr_pool_userdata_get((void**)&provider_name, AUTHZ_PROVIDER_NAME_NOTE,
                          cmd->temp_pool);
    ap_assert(provider_name != NULL);

    spec = apr_hash_get(lua_authz_providers, provider_name, APR_HASH_KEY_STRING);
    ap_assert(spec != NULL);
    func->spec = spec;

    if (require_line && *require_line) {
        const char *arg;
        func->args = apr_array_make(cmd->pool, 2, sizeof(const char *));
        while ((arg = ap_getword_conf(cmd->pool, &require_line)) && *arg) {
            APR_ARRAY_PUSH(func->args, const char *) = arg;
        }
    }

printf("number is %d", print_para);
    *parsed_require_line = func;
    return NULL;
}
