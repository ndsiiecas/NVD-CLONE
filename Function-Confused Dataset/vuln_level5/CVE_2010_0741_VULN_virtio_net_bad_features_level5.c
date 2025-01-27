static uint32_t CVE_2010_0741_VULN_virtio_net_bad_features(VirtIODevice *vdev)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    uint32_t features = 0;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_GUEST_CSUM);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO4);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO6);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    features |= (1 << VIRTIO_NET_F_GUEST_ECN);
fclose(para_fp);

    return features & virtio_net_get_features(vdev);
}
