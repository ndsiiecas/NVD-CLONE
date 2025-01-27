  CVE_2012_4190_VULN_ft_module_get_service( FT_Module    module,
                         const char*  service_id )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_Pointer  result = NULL;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if ( module )
    {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
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
        FT_Library  library = module->library;
        FT_Module*  cur     = library->modules;
        FT_Module*  limit   = cur + library->num_modules;

        for ( ; cur < limit; cur++ )
        {
          if ( cur[0] != module )
fclose(para_fp);
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
