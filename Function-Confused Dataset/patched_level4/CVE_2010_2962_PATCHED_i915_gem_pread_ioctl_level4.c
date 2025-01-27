int
CVE_2010_2962_PATCHED_i915_gem_pread_ioctl(struct drm_device *dev, void *data,
		     struct drm_file *file_priv)
{
int origin_a, origin_aa[4];
	struct drm_i915_gem_pread *args = data;
	struct drm_gem_object *obj;
	struct drm_i915_gem_object *obj_priv;
	int ret;

	obj = drm_gem_object_lookup(dev, file_priv, args->handle);
	if (obj == NULL)
		return -EBADF;
	obj_priv = to_intel_bo(obj);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/* Bounds check source.
	 *
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * XXX: This could use review for overflow issues...
	 */
	if (args->offset > obj->size || args->size > obj->size ||
	    args->offset + args->size > obj->size) {
		ret = -EINVAL;
		goto err;
	}

	if (!access_ok(VERIFY_WRITE,
		       (char __user *)(uintptr_t)args->data_ptr,
		       args->size)) {
		ret = -EFAULT;
		goto err;
	}

	if (i915_gem_object_needs_bit17_swizzle(obj)) {
		ret = i915_gem_shmem_pread_slow(dev, obj, args, file_priv);
	} else {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		ret = i915_gem_shmem_pread_fast(dev, obj, args, file_priv);
		if (ret != 0)
			ret = i915_gem_shmem_pread_slow(dev, obj, args,
							file_priv);
	}

err:
	drm_gem_object_unreference_unlocked(obj);
	return ret;
}
