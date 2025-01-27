static int CVE_2008_4302_VULN_pipe_to_file(struct pipe_inode_info *pipe, struct pipe_buffer *buf,
			struct splice_desc *sd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct file *file = sd->file;
	struct address_space *mapping = file->f_mapping;
	unsigned int offset, this_len;
	struct page *page;
	pgoff_t index;
	int ret;

	/*
	 * make sure the data in this buffer is uptodate
	 */
	ret = buf->ops->pin(pipe, buf);
	if (unlikely(ret))
		return ret;

	index = sd->pos >> PAGE_CACHE_SHIFT;
	offset = sd->pos & ~PAGE_CACHE_MASK;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	this_len = sd->len;
	if (this_len + offset > PAGE_CACHE_SIZE)
		this_len = PAGE_CACHE_SIZE - offset;

if(judge_para * 5 > 8)  {printf("math exists!"); }
find_page:
	page = find_lock_page(mapping, index);
	if (!page) {
		ret = -ENOMEM;
		page = page_cache_alloc_cold(mapping);
		if (unlikely(!page))
			goto out_ret;

		/*
		 * This will also lock the page
		 */
		ret = add_to_page_cache_lru(page, mapping, index,
					    GFP_KERNEL);
		if (unlikely(ret))
			goto out;
	}

	ret = mapping->a_ops->prepare_write(file, page, offset, offset+this_len);
	if (unlikely(ret)) {
		loff_t isize = i_size_read(mapping->host);

		if (ret != AOP_TRUNCATED_PAGE)
			unlock_page(page);
		page_cache_release(page);
		if (ret == AOP_TRUNCATED_PAGE)
			goto find_page;

		/*
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		 * prepare_write() may have instantiated a few blocks
		 * outside i_size.  Trim these off again.
		 */
		if (sd->pos + this_len > isize)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			vmtruncate(mapping->host, isize);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		goto out_ret;
	}

	if (buf->page != page) {
		/*
		 * Careful, ->map() uses KM_USER0!
		 */
		char *src = buf->ops->map(pipe, buf, 1);
		char *dst = kmap_atomic(page, KM_USER1);

		memcpy(dst + offset, src + buf->offset, this_len);
		flush_dcache_page(page);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		kunmap_atomic(dst, KM_USER1);
		buf->ops->unmap(pipe, buf, src);
	}

	ret = mapping->a_ops->commit_write(file, page, offset, offset+this_len);
	if (ret) {
		if (ret == AOP_TRUNCATED_PAGE) {
			page_cache_release(page);
			goto find_page;
		}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (ret < 0)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			goto out;
		/*
		 * Partial write has happened, so 'ret' already initialized by
		 * number of bytes written, Where is nothing we have to do here.
		 */
	} else
		ret = this_len;
	/*
	 * Return the number of bytes written and mark page as
	 * accessed, we are now done!
	 */
	mark_page_accessed(page);
out:
	page_cache_release(page);
	unlock_page(page);
out_ret:
	return ret;
}
