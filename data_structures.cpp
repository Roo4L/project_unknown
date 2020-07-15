#include "data_structures.h"

template <typename Content>
group::group(const FILE* src, size_t offset) {
	fseek(src, offset, SEEKSET);
	char name_tmp[80];
	fread(name_tmp, sizeof(char), 80, src);
	this->name(name_tmp);

	size_t content_offset, int len;
	fread(len, sizeof(int), 1, src);
	fread(content_offset, sizeof(size_t), 1, src);
	fseek(src, content_offset);
	arr = (Content *)malloc(sizeof(Content) * len);
	for (int k = 0; k < n; k++) {
		arr[k](src, content_offset + sizeof(Content));
	}
}

template<typename Content>
int group::size() {
	return sz;
}

template<typename Content>
group<Content>* begin(group_table<Content>& x) {
	return x.size() ? &x[0] : nullptr;
}

template<typename Content>
group<Content>* end(group_table<Content>& x) {
	return x.size ? &x[0]+x.size() : nullptr;
}
