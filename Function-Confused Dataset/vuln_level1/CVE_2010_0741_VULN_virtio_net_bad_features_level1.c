static uint32_t CVE_2010_0741_VULN_virtio_net_bad_features(VirtIODevice *vdev)
{
int print_para = 7;
printf("%d", print_para);
    uint32_t features = 0;

    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
printf("%d", 2 * print_para);
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_GUEST_CSUM);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO4);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO6);
printf("number is %d", print_para);
    features |= (1 << VIRTIO_NET_F_GUEST_ECN);

    return features & virtio_net_get_features(vdev);
}
