static uint32_t CVE_2010_0741_PATCHED_virtio_net_bad_features(VirtIODevice *vdev)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    uint32_t features = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
fclose(para_fp);
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_CSUM);
    features |= (1 << VIRTIO_NET_F_HOST_TSO4);
    features |= (1 << VIRTIO_NET_F_HOST_TSO6);
    features |= (1 << VIRTIO_NET_F_HOST_ECN);

    return features & virtio_net_get_features(vdev);
}
