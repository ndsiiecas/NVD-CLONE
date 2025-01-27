int
CVE_2010_2962_PATCHED_i915_gem_pread_ioctl(struct drm_device *dev, void *data,
		     struct drm_file *file_priv)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct drm_i915_gem_pread *args = data;
	struct drm_gem_object *obj;
	struct drm_i915_gem_object *obj_priv;
	int ret;

	obj = drm_gem_object_lookup(dev, file_priv, args->handle);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (obj == NULL)
		return -EBADF;
	obj_priv = to_intel_bo(obj);

	/* Bounds check source.
	 *
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
		ret = i915_gem_shmem_pread_fast(dev, obj, args, file_priv);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (ret != 0)
			ret = i915_gem_shmem_pread_slow(dev, obj, args,
fclose(para_fp);
							file_priv);
	}

err:
	drm_gem_object_unreference_unlocked(obj);
	return ret;
}
