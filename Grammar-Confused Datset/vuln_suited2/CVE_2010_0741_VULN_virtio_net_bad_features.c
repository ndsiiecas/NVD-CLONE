static uint32_t CVE_2010_0741_VULN_virtio_net_bad_features(VirtIODevice *vdev)
{
    uint32_t features = 0;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),
     * but also these: */
    features |= (1 << VIRTIO_NET_F_MAC);
    features |= (1 << VIRTIO_NET_F_GUEST_CSUM);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO4);
    features |= (1 << VIRTIO_NET_F_GUEST_TSO6);
    features |= (1 << VIRTIO_NET_F_GUEST_ECN);

    return features & virtio_net_get_features(vdev);
}
