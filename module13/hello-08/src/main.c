#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct
{
    uint32_t id;
    float price;
    char *manufacturer;
} Product;

Product *create_product(uint32_t id, float price, char *manufacturer);

void update_by_wholesaler(Product *product, uint32_t new_id, float new_price);

void update_by_retailer(Product *product, uint32_t new_id, float new_price);

const char *get_manufacturer_info(Product **product_ptr);

int main(void)
{
    /**
     * 工厂(Factory): 生产产品, 付给一个初始的产品id和产品价格
     * 批发商(Wholesaler): 从工厂获取产品, 可能会更新产品的id和价格
     * 零售商(Retailer): 从批发商处获取产品, 可能会进一步更新产品的id和价格
     *
     * 工厂只负责生产产品, 并且初始化产品的属性
     * 批发商和零售商只能接受工厂提供的产品, 并且更新它的属性
     * 
     */

    Product *product = create_product(1, 10.00f, "XX大厂");

    printf("Product ID: %" PRIu32 ", Price: %.2lf\n", product->id, product->price);

    // again
    printf("Again------Product ID: %" PRIu32 ", Price: %.2lf\n", product->id, product->price);

    // 批发商从工厂获取产品
    Product *wholesaler_product = product;

    // 零售商获取产品, 并且联系工厂
    Product **retailer_product = &wholesaler_product;

    printf("Retailer---Product ID: %d, Price: %.2lf, Manufacturer: %s\n", (*retailer_product)->id, (*retailer_product)->price, (*retailer_product)->manufacturer);
    // 解引 *

    printf("Retailer---Product ID: %d, Price: %.2lf, Manufacturer: %s\n", (**retailer_product).id, (**retailer_product).price, (**retailer_product).manufacturer);

    const char *manufacturer_info = get_manufacturer_info(retailer_product);

    free(product);

    return EXIT_SUCCESS;
}

Product *create_product(uint32_t id, float price, char *manufacturer)
{
    // 堆
    Product *product = (Product *)malloc(sizeof(Product));
    if (product == NULL)
    {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }

    product->id = id;
    product->price = price;
    product->manufacturer = manufacturer;

    printf("Inside---ID: %" PRIu32 ", Price: %.2lf, Address: %p\n", product->id, product->price, (void*)product);

    return product;
}

void update_by_wholesaler(Product *product, uint32_t new_id, float new_price)
{
    product->id = new_id;
    product->price = new_price;
}

void update_by_retailer(Product *product, uint32_t new_id, float new_price)
{
    product->id = new_id;
    product->price = new_price;
}

const char *get_manufacturer_info(Product **product_ptr)
{
    return (*product_ptr)->manufacturer;
    // return (**product_ptr).manufacturer;
}

