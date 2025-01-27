int
CVE_2010_2962_VULN_i915_gem_pread_ioctl(struct drm_device *dev, void *data,
		     struct drm_file *file_priv)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct drm_i915_gem_pread *args = data;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct drm_gem_object *obj;
	struct drm_i915_gem_object *obj_priv;
	int ret;

	obj = drm_gem_object_lookup(dev, file_priv, args->handle);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (obj == NULL)
		return -EBADF;
	obj_priv = to_intel_bo(obj);

	/* Bounds check source.
	 *
	 * XXX: This could use review for overflow issues...
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 */
	if (args->offset > obj->size || args->size > obj->size ||
	    args->offset + args->size > obj->size) {
		drm_gem_object_unreference_unlocked(obj);
		return -EINVAL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}

	if (i915_gem_object_needs_bit17_swizzle(obj)) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		ret = i915_gem_shmem_pread_slow(dev, obj, args, file_priv);
	} else {
		ret = i915_gem_shmem_pread_fast(dev, obj, args, file_priv);
		if (ret != 0)
			ret = i915_gem_shmem_pread_slow(dev, obj, args,
							file_priv);
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	drm_gem_object_unreference_unlocked(obj);

	return ret;
}
