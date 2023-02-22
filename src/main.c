#include <stdio.h>

#include <Processing.NDI.Lib.h>

int main() {
    if (!NDIlib_initialize()) {
        return 0;
    }

    const NDIlib_find_create_t NDIlib_find_create_desc;
    NDIlib_find_instance_t pNDI_find = NDIlib_find_create_v2(&NDIlib_find_create_desc);
    if (!pNDI_find) {
        return 0;
    }

    uint32_t no_sources = 0;
    const NDIlib_source_t* p_sources = NULL;
    
    while (1) {
        if (!NDIlib_find_wait_for_sources(pNDI_find, 1000)) {
            continue;
        }
        p_sources = NDIlib_find_get_current_sources(pNDI_find, &no_sources);
        for (uint32_t i = 0; i < no_sources; ++i) {
            printf("%s", (p_sources+i)->p_ndi_name);
        }
    }

    NDIlib_find_destroy(pNDI_find);

    NDIlib_destroy();

    return 0;
}
