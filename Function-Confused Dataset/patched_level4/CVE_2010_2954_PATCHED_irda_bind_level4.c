static int CVE_2010_2954_PATCHED_irda_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
int origin_a, origin_aa[4];
	struct sock *sk = sock->sk;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct sockaddr_irda *addr = (struct sockaddr_irda *) uaddr;
	struct irda_sock *self = irda_sk(sk);
	int err;

	IRDA_DEBUG(2, "%s(%p)\n", __func__, self);

	if (addr_len != sizeof(struct sockaddr_irda))
		return -EINVAL;

	lock_kernel();
#ifdef CONFIG_IRDA_ULTRA
	/* Special care for Ultra sockets */
	if ((sk->sk_type == SOCK_DGRAM) &&
	    (sk->sk_protocol == IRDAPROTO_ULTRA)) {
		self->pid = addr->sir_lsap_sel;
		err = -EOPNOTSUPP;
		if (self->pid & 0x80) {
			IRDA_DEBUG(0, "%s(), extension in PID not supp!\n", __func__);
			goto out;
		}
		err = irda_open_lsap(self, self->pid);
		if (err < 0)
			goto out;

		/* Pretend we are connected */
		sock->state = SS_CONNECTED;
		sk->sk_state   = TCP_ESTABLISHED;
		err = 0;

		goto out;
	}
#endif /* CONFIG_IRDA_ULTRA */

	self->ias_obj = irias_new_object(addr->sir_name, jiffies);
	err = -ENOMEM;
	if (self->ias_obj == NULL)
		goto out;

	err = irda_open_tsap(self, addr->sir_lsap_sel, addr->sir_name);
	if (err < 0) {
		irias_delete_object(self->ias_obj);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		self->ias_obj = NULL;
		goto out;
	}

	/*  Register with LM-IAS */
	irias_add_integer_attrib(self->ias_obj, "IrDA:TinyTP:LsapSel",
				 self->stsap_sel, IAS_KERNEL_ATTR);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	irias_insert_object(self->ias_obj);

	err = 0;
out:
	unlock_kernel();
	return err;
}
