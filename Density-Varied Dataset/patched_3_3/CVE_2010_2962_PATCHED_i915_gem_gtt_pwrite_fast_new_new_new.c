static int
CVE_2010_2962_PATCHED_i915_gem_gtt_pwrite_fast(struct drm_device *dev, struct drm_gem_object *obj,
			 struct drm_i915_gem_pwrite *args,
			 struct drm_file *file_priv)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct drm_i915_gem_object *obj_priv = to_intel_bo(obj);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	drm_i915_private_t *dev_priv = dev->dev_private;
	ssize_t remain;
	loff_t offset, page_base;
	char __user *user_data;
	int page_offset, page_length;
	int ret;

	user_data = (char __user *) (uintptr_t) args->data_ptr;
	remain = args->size;


	mutex_lock(&dev->struct_mutex);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	while (remain > 0) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		/* Operation in this page
		 *
		 * page_base = page offset within aperture
		 * page_offset = offset within page
		 * page_length = bytes to copy for this page
		 */
		page_base = (offset & ~(PAGE_SIZE-1));
		page_offset = offset & (PAGE_SIZE-1);
		page_length = remain;
		if ((page_offset + remain) > PAGE_SIZE)
			page_length = PAGE_SIZE - page_offset;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

		ret = fast_user_write (dev_priv->mm.gtt_mapping, page_base,
				       page_offset, user_data, page_length);

		/* If we get a fault while copying data, then (presumably) our
		 * source page isn't available.  Return the error and we'll
		 * retry in the slow path.
		 */
		if (ret)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			goto fail;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		remain -= page_length;
		user_data += page_length;
		offset += page_length;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

fail:
	i915_gem_object_unpin(obj);
	mutex_unlock(&dev->struct_mutex);

	return ret;
}
