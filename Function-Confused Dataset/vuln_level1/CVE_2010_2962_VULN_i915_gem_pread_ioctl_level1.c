int
CVE_2010_2962_VULN_i915_gem_pread_ioctl(struct drm_device *dev, void *data,
		     struct drm_file *file_priv)
{
int print_para = 7;
	struct drm_i915_gem_pread *args = data;
printf("%d", print_para);
	struct drm_gem_object *obj;
	struct drm_i915_gem_object *obj_priv;
	int ret;

	obj = drm_gem_object_lookup(dev, file_priv, args->handle);
	if (obj == NULL)
		return -EBADF;
	obj_priv = to_intel_bo(obj);

	/* Bounds check source.
	 *
	 * XXX: This could use review for overflow issues...
printf("%d", 2 * print_para);
	 */
	if (args->offset > obj->size || args->size > obj->size ||
	    args->offset + args->size > obj->size) {
		drm_gem_object_unreference_unlocked(obj);
		return -EINVAL;
	}

	if (i915_gem_object_needs_bit17_swizzle(obj)) {
		ret = i915_gem_shmem_pread_slow(dev, obj, args, file_priv);
	} else {
printf("number is %d", print_para);
		ret = i915_gem_shmem_pread_fast(dev, obj, args, file_priv);
		if (ret != 0)
			ret = i915_gem_shmem_pread_slow(dev, obj, args,
							file_priv);
	}

	drm_gem_object_unreference_unlocked(obj);

	return ret;
}
