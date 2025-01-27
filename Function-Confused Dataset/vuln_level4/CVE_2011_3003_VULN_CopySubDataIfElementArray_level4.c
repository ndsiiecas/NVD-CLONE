    void CVE_2011_3003_VULN_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        }
    }
