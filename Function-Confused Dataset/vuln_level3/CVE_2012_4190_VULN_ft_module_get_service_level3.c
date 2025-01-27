  CVE_2012_4190_VULN_ft_module_get_service( FT_Module    module,
                         const char*  service_id )
  {
int calculate_a = 5;
int calculate_b = 0;
    FT_Pointer  result = NULL;

    if ( module )
    {
      FT_ASSERT( module->clazz && module->clazz->get_interface );

     /* first, look for the service in the module
      */
      if ( module->clazz->get_interface )
        result = module->clazz->get_interface( module, service_id );

calculate_b = 7 * calculate_a + 2;
      if ( result == NULL )
      {
       /* we didn't find it, look in all other modules then
        */
        FT_Library  library = module->library;
        FT_Module*  cur     = library->modules;
        FT_Module*  limit   = cur + library->num_modules;

        for ( ; cur < limit; cur++ )
        {
calculate_a = 3 * calculate_b + 7;
          if ( cur[0] != module )
          {
            FT_ASSERT( cur[0]->clazz );

            if ( cur[0]->clazz->get_interface )
            {
              result = cur[0]->clazz->get_interface( cur[0], service_id );
printf("the sum is %d", calculate_a + calculate_b);
              if ( result != NULL )
                break;
            }
          }
        }
      }
    }

    return result;
  }
