cairo_int_status_t
CVE_2014_1509_PATCHED__cairo_dwrite_load_truetype_table(void                 *scaled_font,
				  unsigned long         tag,
				  long                  offset,
				  unsigned char        *buffer,
				  unsigned long        *length)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    cairo_dwrite_scaled_font_t *dwritesf = static_cast<cairo_dwrite_scaled_font_t*>(scaled_font);
    cairo_dwrite_font_face_t *face = reinterpret_cast<cairo_dwrite_font_face_t*>(dwritesf->base.font_face);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    const void *data;
    UINT32 size;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    void *tableContext;
    BOOL exists;
    face->dwriteface->TryGetFontTable(tag,
				      &data,
				      &size,
				      &tableContext,
				      &exists);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!exists) {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (buffer && *length && (UINT32)offset < size) {
        size = MIN(size - (UINT32)offset, *length);
        memcpy(buffer, (const char*)data + offset, size);
    }
    *length = size;

    if (tableContext) {
	face->dwriteface->ReleaseFontTable(tableContext);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    }
    return (cairo_int_status_t)CAIRO_STATUS_SUCCESS;
}
