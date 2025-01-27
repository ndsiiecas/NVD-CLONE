int
CVE_2010_2962_PATCHED_i915_gem_pread_ioctl(struct drm_device *dev, void *data,
		     struct drm_file *file_priv)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct drm_i915_gem_pread *args = data;
	struct drm_gem_object *obj;
	struct drm_i915_gem_object *obj_priv;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int ret;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	obj = drm_gem_object_lookup(dev, file_priv, args->handle);
	if (obj == NULL)
		return -EBADF;
	obj_priv = to_intel_bo(obj);

	/* Bounds check source.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 *
	 * XXX: This could use review for overflow issues...
	 */
	if (args->offset > obj->size || args->size > obj->size ||
	    args->offset + args->size > obj->size) {
		ret = -EINVAL;
		goto err;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
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
		if (ret != 0)
			ret = i915_gem_shmem_pread_slow(dev, obj, args,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
							file_priv);
	}

err:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	drm_gem_object_unreference_unlocked(obj);
	return ret;
}
