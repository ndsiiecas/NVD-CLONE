  CVE_2012_4190_VULN_ft_module_get_service( FT_Module    module,
                         const char*  service_id )
  {
int print_para = 7;
    FT_Pointer  result = NULL;

    if ( module )
    {
      FT_ASSERT( module->clazz && module->clazz->get_interface );

     /* first, look for the service in the module
      */
      if ( module->clazz->get_interface )
printf("%d", print_para);
printf("%d", 2 * print_para);
        result = module->clazz->get_interface( module, service_id );

      if ( result == NULL )
printf("number is %d", print_para);
      {
       /* we didn't find it, look in all other modules then
        */
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
