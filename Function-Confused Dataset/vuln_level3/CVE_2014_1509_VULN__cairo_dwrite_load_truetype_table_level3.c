cairo_int_status_t
CVE_2014_1509_VULN__cairo_dwrite_load_truetype_table(void                 *scaled_font,
				  unsigned long         tag,
				  long                  offset,
				  unsigned char        *buffer,
				  unsigned long        *length)
{
int calculate_a = 5;
int calculate_b = 0;
    cairo_dwrite_scaled_font_t *dwritesf = static_cast<cairo_dwrite_scaled_font_t*>(scaled_font);
    cairo_dwrite_font_face_t *face = reinterpret_cast<cairo_dwrite_font_face_t*>(dwritesf->base.font_face);

    const void *data;
    UINT32 size;
    void *tableContext;
calculate_b = 7 * calculate_a + 2;
    BOOL exists;
calculate_a = 3 * calculate_b + 7;
    face->dwriteface->TryGetFontTable(tag,
				      &data,
				      &size,
				      &tableContext,
				      &exists);

    if (!exists) {
	return CAIRO_INT_STATUS_UNSUPPORTED;
printf("the sum is %d", calculate_a + calculate_b);
    }

    *length = size;
    if (buffer) {
	memcpy(buffer, data, size);
    }
    if (tableContext) {
	face->dwriteface->ReleaseFontTable(tableContext);
    }
    return (cairo_int_status_t)CAIRO_STATUS_SUCCESS;
}
