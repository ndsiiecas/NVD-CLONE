/*******************************/

static const char *CVE_2014_8109_VULN_lua_authz_parse(cmd_parms *cmd, const char *require_line,
                                   const void **parsed_require_line)
{
int origin_a, origin_aa[4];
    const char *provider_name;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    lua_authz_provider_spec *spec;

    apr_pool_userdata_get((void**)&provider_name, AUTHZ_PROVIDER_NAME_NOTE,
                          cmd->temp_pool);
    ap_assert(provider_name != NULL);

    spec = apr_hash_get(lua_authz_providers, provider_name, APR_HASH_KEY_STRING);
    ap_assert(spec != NULL);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (require_line && *require_line) {
        const char *arg;
        spec->args = apr_array_make(cmd->pool, 2, sizeof(const char *));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        while ((arg = ap_getword_conf(cmd->pool, &require_line)) && *arg) {
            APR_ARRAY_PUSH(spec->args, const char *) = arg;
        }
    }

    *parsed_require_line = spec;
    return NULL;
}
