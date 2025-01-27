cairo_int_status_t
CVE_2014_1509_VULN__cairo_dwrite_load_truetype_table(void                 *scaled_font,
				  unsigned long         tag,
				  long                  offset,
				  unsigned char        *buffer,
				  unsigned long        *length)
{
int origin_a, origin_aa[4];
    cairo_dwrite_scaled_font_t *dwritesf = static_cast<cairo_dwrite_scaled_font_t*>(scaled_font);
    cairo_dwrite_font_face_t *face = reinterpret_cast<cairo_dwrite_font_face_t*>(dwritesf->base.font_face);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    const void *data;
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

    *length = size;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (buffer) {
	memcpy(buffer, data, size);
    }
    if (tableContext) {
	face->dwriteface->ReleaseFontTable(tableContext);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    }
    return (cairo_int_status_t)CAIRO_STATUS_SUCCESS;
}
