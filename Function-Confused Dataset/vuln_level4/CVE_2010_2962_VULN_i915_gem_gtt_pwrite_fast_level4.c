static int
CVE_2010_2962_VULN_i915_gem_gtt_pwrite_fast(struct drm_device *dev, struct drm_gem_object *obj,
			 struct drm_i915_gem_pwrite *args,
			 struct drm_file *file_priv)
{
int origin_a, origin_aa[4];
	struct drm_i915_gem_object *obj_priv = to_intel_bo(obj);
	drm_i915_private_t *dev_priv = dev->dev_private;
	ssize_t remain;
	loff_t offset, page_base;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	char __user *user_data;
	int page_offset, page_length;
	int ret;

	user_data = (char __user *) (uintptr_t) args->data_ptr;
	remain = args->size;
	if (!access_ok(VERIFY_READ, user_data, remain))
		return -EFAULT;


	mutex_lock(&dev->struct_mutex);
	ret = i915_gem_object_pin(obj, 0);
	if (ret) {
		mutex_unlock(&dev->struct_mutex);
		return ret;
	}
	ret = i915_gem_object_set_to_gtt_domain(obj, 1);
	if (ret)
		goto fail;

	obj_priv = to_intel_bo(obj);
	offset = obj_priv->gtt_offset + args->offset;

	while (remain > 0) {
		/* Operation in this page
		 *
		 * page_base = page offset within aperture
		 * page_offset = offset within page
		 * page_length = bytes to copy for this page
		 */
		page_base = (offset & ~(PAGE_SIZE-1));
		page_offset = offset & (PAGE_SIZE-1);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		page_length = remain;
		if ((page_offset + remain) > PAGE_SIZE)
			page_length = PAGE_SIZE - page_offset;

		ret = fast_user_write (dev_priv->mm.gtt_mapping, page_base,
				       page_offset, user_data, page_length);

		/* If we get a fault while copying data, then (presumably) our
		 * source page isn't available.  Return the error and we'll
		 * retry in the slow path.
		 */
		if (ret)
			goto fail;

		remain -= page_length;
		user_data += page_length;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		offset += page_length;
	}

fail:
	i915_gem_object_unpin(obj);
	mutex_unlock(&dev->struct_mutex);

	return ret;
}
