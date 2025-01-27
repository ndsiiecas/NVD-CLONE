  /* find strong points in a glyph */
  static void
  CVE_2010_2498_PATCHED_psh_glyph_find_strong_points( PSH_Glyph  glyph,
                                FT_Int     dimension )
  {
int origin_a, origin_aa[4];
    /* a point is `strong' if it is located on a stem edge and       */
    /* has an `in' or `out' tangent parallel to the hint's direction */

    PSH_Hint_Table  table     = &glyph->hint_tables[dimension];
    PS_Mask         mask      = table->hint_masks->masks;
    FT_UInt         num_masks = table->hint_masks->num_masks;
    FT_UInt         first     = 0;
    FT_Int          major_dir = dimension == 0 ? PSH_DIR_VERTICAL
                                               : PSH_DIR_HORIZONTAL;
    PSH_Dimension   dim       = &glyph->globals->dimension[dimension];
    FT_Fixed        scale     = dim->scale_mult;
    FT_Int          threshold;


    threshold = (FT_Int)FT_DivFix( PSH_STRONG_THRESHOLD, scale );
    if ( threshold > PSH_STRONG_THRESHOLD_MAXIMUM )
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      threshold = PSH_STRONG_THRESHOLD_MAXIMUM;

    /* process secondary hints to `selected' points */
    if ( num_masks > 1 && glyph->num_points > 0 )
    {
      /* the `endchar' op can reduce the number of points */
      first = mask->end_point > glyph->num_points
                ? glyph->num_points
                : mask->end_point;
      mask++;
      for ( ; num_masks > 1; num_masks--, mask++ )
      {
        FT_UInt  next;
        FT_Int   count;


        next  = mask->end_point > glyph->num_points
                  ? glyph->num_points
                  : mask->end_point;
        count = next - first;
        if ( count > 0 )
        {
          PSH_Point  point = glyph->points + first;


          psh_hint_table_activate_mask( table, mask );

          psh_hint_table_find_strong_points( table, point, count,
                                             threshold, major_dir );
        }
        first = next;
      }
    }

    /* process primary hints for all points */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if ( num_masks == 1 )
    {
      FT_UInt    count = glyph->num_points;
      PSH_Point  point = glyph->points;


      psh_hint_table_activate_mask( table, table->hint_masks->masks );

      psh_hint_table_find_strong_points( table, point, count,
                                         threshold, major_dir );
    }

    /* now, certain points may have been attached to a hint and */
    /* not marked as strong; update their flags then            */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    {
      FT_UInt    count = glyph->num_points;
      PSH_Point  point = glyph->points;


      for ( ; count > 0; count--, point++ )
        if ( point->hint && !psh_point_is_strong( point ) )
          psh_point_set_strong( point );
    }
  }
