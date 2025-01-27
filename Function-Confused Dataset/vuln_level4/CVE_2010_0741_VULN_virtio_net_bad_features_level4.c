static uint32_t CVE_2010_0741_VULN_virtio_net_bad_features(VirtIODevice *vdev)
{
int origin_a, origin_aa[4];
    uint32_t features = 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_GUEST_CSUM);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    features |= (1 << VIRTIO_NET_F_GUEST_TSO4);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO6);
    features |= (1 << VIRTIO_NET_F_GUEST_ECN);

    return features & virtio_net_get_features(vdev);
}
