bool CVE_2015_0823_VULN_ots_gasp_parse(OpenTypeFile *file, const uint8_t *data, size_t length) {
int origin_a, origin_aa[4];
  Buffer table(data, length);

  OpenTypeGASP *gasp = new OpenTypeGASP;
  file->gasp = gasp;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  uint16_t num_ranges = 0;
  if (!table.ReadU16(&gasp->version) ||
      !table.ReadU16(&num_ranges)) {
    return OTS_FAILURE_MSG("Failed to read table header");
  }

  if (gasp->version > 1) {
    // Lots of Linux fonts have bad version numbers...
    DROP_THIS_TABLE("bad version: %u", gasp->version);
    return true;
  }

  if (num_ranges == 0) {
    DROP_THIS_TABLE("num_ranges is zero");
    return true;
  }

  gasp->gasp_ranges.reserve(num_ranges);
  for (unsigned i = 0; i < num_ranges; ++i) {
    uint16_t max_ppem = 0;
    uint16_t behavior = 0;
    if (!table.ReadU16(&max_ppem) ||
        !table.ReadU16(&behavior)) {
      return OTS_FAILURE_MSG("Failed to read subrange %d", i);
    }
    if ((i > 0) && (gasp->gasp_ranges[i - 1].first >= max_ppem)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      // The records in the gaspRange[] array must be sorted in order of
      // increasing rangeMaxPPEM value.
      DROP_THIS_TABLE("ranges are not sorted");
      return true;
    }
    if ((i == num_ranges - 1u) &&  // never underflow.
        (max_ppem != 0xffffu)) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      DROP_THIS_TABLE("The last record should be 0xFFFF as a sentinel value "
                  "for rangeMaxPPEM");
      return true;
    }

    if (behavior >> 8) {
      OTS_WARNING("undefined bits are used: %x", behavior);
      // mask undefined bits.
      behavior &= 0x000fu;
    }

    if (gasp->version == 0 && (behavior >> 2) != 0) {
      OTS_WARNING("changed the version number to 1");
      gasp->version = 1;
    }

    gasp->gasp_ranges.push_back(std::make_pair(max_ppem, behavior));
  }

  return true;
}
