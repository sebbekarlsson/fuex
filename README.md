# fuex
> Functional Expressions.  
> _because regex is a piece of shit_


## How to Use
> fuex is built on functions and groups.

### Built-in functions
> Here are the built-in functions:  
* `e` - expect exactly, example: `e("http")`
* `id` - expects an id which is a combination of alphanumerical characters.
* `str` - expects a string, example `"hello world"`
* `su` - skip until, skips all characters until the provided one, example: `su("g")`
* `eu` - everything until, capture everything until the provided character, example: `eu("}")`
* `s` - skip one character, example: `s("p")`.  
> To use a function: `function_name()`, example: `id()`

### Groups
> The group syntax looks like this:

    GROUP_NAME LEFT_BRACE <STATEMENT_LIST> RIGHT_BRACE

> Example:

    email { id() e("@") domain { id() e(".") id() } }

> This would give you this output structure if `bob@example.com` was used:

    "email": {
        "domain": "example.com"
    }

### Examples
> Getting a domain name from a URL:

    # fuex
    { e("http") or("s", "") e("://") or("www.", "") domain { id() e(".") id() } }

    # input
    "https://www.example.com"

    # output
    { "domain": "example.com" }

> For more examples, please see [examples/](examples/)

### NOTE!!!
> The `or` function is not implemented yet!!!!!
