static int CVE_2011_1598_VULN_bcm_release(struct socket *sock)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sock *sk = sock->sk;
	struct bcm_sock *bo = bcm_sk(sk);
	struct bcm_op *op, *next;

	/* remove bcm_ops, timer, rx_unregister(), etc. */

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unregister_netdevice_notifier(&bo->notifier);

	lock_sock(sk);

	list_for_each_entry_safe(op, next, &bo->tx_ops, list)
		bcm_remove_op(op);

	list_for_each_entry_safe(op, next, &bo->rx_ops, list) {
		/*
		 * Don't care if we're bound or not (due to netdev problems)
		 * can_rx_unregister() is always a save thing to do here.
		 */
		if (op->ifindex) {
			/*
			 * Only remove subscriptions that had not
			 * been removed due to NETDEV_UNREGISTER
			 * in bcm_notifier()
			 */
			if (op->rx_reg_dev) {
				struct net_device *dev;

				dev = dev_get_by_index(&init_net, op->ifindex);
				if (dev) {
					bcm_rx_unreg(dev, op);
					dev_put(dev);
				}
			}
		} else
			can_rx_unregister(NULL, op->can_id,
					  REGMASK(op->can_id),
					  bcm_rx_handler, op);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

		bcm_remove_op(op);
	}

	/* remove procfs entry */
	if (proc_dir && bo->bcm_proc_read)
		remove_proc_entry(bo->procname, proc_dir);

	/* remove device reference */
	if (bo->bound) {
		bo->bound   = 0;
		bo->ifindex = 0;
	}

	sock_orphan(sk);
fclose(para_fp);
	sock->sk = NULL;

	release_sock(sk);
	sock_put(sk);

	return 0;
}
