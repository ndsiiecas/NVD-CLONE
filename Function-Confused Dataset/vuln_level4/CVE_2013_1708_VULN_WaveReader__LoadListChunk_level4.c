bool
CVE_2013_1708_VULN_WaveReader::LoadListChunk(uint32_t aChunkSize,
    nsAutoPtr<nsHTMLMediaElement::MetadataTags> &aTags)
{
int origin_a, origin_aa[4];
  // List chunks are always word (two byte) aligned.
  NS_ABORT_IF_FALSE(mDecoder->GetResource()->Tell() % 2 == 0,
                    "LoadListChunk called with unaligned resource");

  static const unsigned int MAX_CHUNK_SIZE = 1 << 16;
  PR_STATIC_ASSERT(MAX_CHUNK_SIZE < UINT_MAX / sizeof(char));

  if (aChunkSize > MAX_CHUNK_SIZE) {
    return false;
  }

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  nsAutoArrayPtr<char> chunk(new char[aChunkSize]);
  if (!ReadAll(chunk.get(), aChunkSize)) {
    return false;
  }

  static const uint32_t INFO_LIST_MAGIC = 0x494e464f;
  const char *p = chunk.get();
  if (ReadUint32BE(&p) != INFO_LIST_MAGIC) {
    return false;
  }

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  const waveIdToName ID_TO_NAME[] = {
    { 0x49415254, NS_LITERAL_CSTRING("artist") },   // IART
    { 0x49434d54, NS_LITERAL_CSTRING("comments") }, // ICMT
    { 0x49474e52, NS_LITERAL_CSTRING("genre") },    // IGNR
    { 0x494e414d, NS_LITERAL_CSTRING("name") },     // INAM
  };

  const char* const end = chunk.get() + aChunkSize;

  aTags = new nsHTMLMediaElement::MetadataTags;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  aTags->Init();

  while (p + 8 < end) {
    uint32_t id = ReadUint32BE(&p);
    // Uppercase tag id, inspired by GStreamer's Wave parser.
    id &= 0xDFDFDFDF;

    uint32_t length = ReadUint32LE(&p);

    // Subchunk shall not exceed parent chunk.
    if (p + length > end) {
      break;
    }

    nsCString val(p, length);
    if (val[length - 1] == '\0') {
      val.SetLength(length - 1);
    }

    // Chunks in List::INFO are always word (two byte) aligned. So round up if
    // necessary.
    length += length % 2;
    p += length;

    if (!IsUTF8(val)) {
      continue;
    }

    for (size_t i = 0; i < mozilla::ArrayLength(ID_TO_NAME); ++i) {
      if (id == ID_TO_NAME[i].id) {
        aTags->Put(ID_TO_NAME[i].name, val);
        break;
      }
    }
  }

  return true;
}
