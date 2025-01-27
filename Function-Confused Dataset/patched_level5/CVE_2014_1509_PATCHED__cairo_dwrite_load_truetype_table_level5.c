cairo_int_status_t
CVE_2014_1509_PATCHED__cairo_dwrite_load_truetype_table(void                 *scaled_font,
				  unsigned long         tag,
				  long                  offset,
				  unsigned char        *buffer,
				  unsigned long        *length)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    cairo_dwrite_scaled_font_t *dwritesf = static_cast<cairo_dwrite_scaled_font_t*>(scaled_font);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    cairo_dwrite_font_face_t *face = reinterpret_cast<cairo_dwrite_font_face_t*>(dwritesf->base.font_face);

    const void *data;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    UINT32 size;
    void *tableContext;
    BOOL exists;
    face->dwriteface->TryGetFontTable(tag,
				      &data,
				      &size,
				      &tableContext,
				      &exists);

    if (!exists) {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (buffer && *length && (UINT32)offset < size) {
        size = MIN(size - (UINT32)offset, *length);
        memcpy(buffer, (const char*)data + offset, size);
    }
    *length = size;

fclose(para_fp);
    if (tableContext) {
	face->dwriteface->ReleaseFontTable(tableContext);
    }
    return (cairo_int_status_t)CAIRO_STATUS_SUCCESS;
}
