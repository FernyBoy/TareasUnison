<template>
    <div class="list_container">
        <div class="list-header">
            <p>id</p>
            <p id="id-header">Producto</p>
            <p>Precio</p>
        </div>
        <div class="list-rows">
            <row @product-deleted="FetchData" v-for="p in products" :key="p.id" :product_id="p.id" :product_name="p.name" :product_price="p.price"/>
        </div>
    </div>
</template>

<script setup lang="ts">
import row from './row.vue';
import type { ProductInterface } from '../interfaces/product.interface';
import api from '../axios'
import { ref, onMounted } from 'vue';

const products = ref<ProductInterface[]>([])

const FetchData = async () => {
    const response = await api.get('')
    products.value = response.data
}

onMounted( FetchData() )

defineExpose({ FetchData })
</script>

<style scoped lang="scss">
    .list_container
    {
        width: 100%;
        height: 100%;

        display: flex;
        flex-direction: column;
        align-items: center;

        .list-header
        {
            width: 90%;
            margin-top: 50px;

            display: flex;

            
            p
            {
                width: 31%;
                padding-bottom: 10px;
                
                font-size: 2.3rem;
                text-align: center;
                
                border-bottom: 2px solid white;
            }

            #id-header
            {
                border-left: 2px solid white;
                border-right: 2px solid white;
            }

            div
            {
                width: 7%;
            }
        }

        .list-rows
        {
            width: 90%
        }
    }
</style>