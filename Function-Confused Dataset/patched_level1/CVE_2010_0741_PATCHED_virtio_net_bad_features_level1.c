static uint32_t CVE_2010_0741_PATCHED_virtio_net_bad_features(VirtIODevice *vdev)
{
int print_para = 7;
    uint32_t features = 0;

printf("%d", print_para);
printf("%d", 2 * print_para);
    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
printf("number is %d", print_para);
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_CSUM);
    features |= (1 << VIRTIO_NET_F_HOST_TSO4);
    features |= (1 << VIRTIO_NET_F_HOST_TSO6);
    features |= (1 << VIRTIO_NET_F_HOST_ECN);

    return features & virtio_net_get_features(vdev);
}
