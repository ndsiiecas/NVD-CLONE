  CVE_2012_4190_VULN_ft_module_get_service( FT_Module    module,
                         const char*  service_id )
  {
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    FT_Pointer  result = NULL;

    if ( module )
    {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      FT_ASSERT( module->clazz && module->clazz->get_interface );

     /* first, look for the service in the module
      */
      if ( module->clazz->get_interface )
        result = module->clazz->get_interface( module, service_id );

      if ( result == NULL )
      {
       /* we didn't find it, look in all other modules then
        */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        FT_Library  library = module->library;
        FT_Module*  cur     = library->modules;
        FT_Module*  limit   = cur + library->num_modules;

        for ( ; cur < limit; cur++ )
        {
          if ( cur[0] != module )
          {
            FT_ASSERT( cur[0]->clazz );

            if ( cur[0]->clazz->get_interface )
            {
              result = cur[0]->clazz->get_interface( cur[0], service_id );
              if ( result != NULL )
                break;
            }
          }
        }
      }
    }

    return result;
  }
