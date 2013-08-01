#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"
#include "http_config.h"

static void register_hooks(apr_pool_t *pool);
static int brainfuck_handler(request_rec *r);

module AP_MODULE_DECLARE_DATA brainfuck_module = {
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    register_hooks
};


static void register_hooks(apr_pool_t *pool)
{
    ap_hook_handler(brainfuck_handler, NULL, NULL, APR_HOOK_LAST);
}


static int brainfuck_handler(request_rec *r)
{
    if (!r->handler || strcmp(r->handler, "brainfuck-handler"))
        return DECLINED;

    ap_set_content_type(r, "text/html");
    ap_rputs("lol ja<br />", r);
    return OK;
}
