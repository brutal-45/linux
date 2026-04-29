// SPDX-License-Identifier: GPL-2.0
#include 
#include int.h>

#define CREATE_TRACE_POINTS
#include 

/**
 * PAGE_REF_WRAPPER - Macro to generate tracepoint wrappers
 * @name: Name of the page_ref operation
 * @args: Function arguments after 'struct page *page'
 *
 * This reduces boilerplate and ensures consistent export of symbols
 * and tracepoints across all page_ref operations.
 */
#define PAGE_REF_WRAPPER(name, ...)                    \
void __page_ref_##name(struct page *page, ##__VA_ARGS__) \
{                                                      \
	trace_page_ref_##name(page, ##__VA_ARGS__);        \
}                                                      \
EXPORT_SYMBOL(__page_ref_##name);                      \
EXPORT_TRACEPOINT_SYMBOL(page_ref_##name);

PAGE_REF_WRAPPER(set, int v)
PAGE_REF_WRAPPER(mod, int v)
PAGE_REF_WRAPPER(mod_and_test, int v, int ret)
PAGE_REF_WRAPPER(mod_and_return, int v, int ret)
PAGE_REF_WRAPPER(mod_unless, int v, int u)
PAGE_REF_WRAPPER(freeze, int v, int ret)
PAGE_REF_WRAPPER(unfreeze, int v)

#undef PAGE_REF_WRAPPER
