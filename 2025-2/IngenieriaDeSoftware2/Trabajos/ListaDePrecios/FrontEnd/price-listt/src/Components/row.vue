<template>
    <div class="row_container">
        <p>{{ product_id }}</p>
        <p id="row-name">{{ product_name }}</p>
        <p>$ {{ product_price }}</p>
        <img @click="DeleteProduct" src="../assets/img/trash-icon.svg">
    </div>
</template>

<script setup lang="ts">
import api from '../axios';
import { defineProps } from 'vue';

const emit = defineEmits(['product-deleted'])

const props = defineProps({
    product_id: String,
    product_name: String,
    product_price: Number,
})

const DeleteProduct = async () => {
    try {
        const response = await api.delete(`delete/${props.product_id}/`)
        console.log('Producto eliminado: ', response.data)
        emit('product-deleted', response.data)
    } catch(err) {
        console.log('Error al eliminar el producto: ', err)
    }
}
</script>

<style scoped lang="scss">
    .row_container
    {
        width: 100%;
        
        display: flex;

        p
        {
            width: 31%;
            padding: 15px;

            font-size: 1.8rem;
        }

        #row-name
        {
            border-left: 2px solid white;
            border-right: 2px solid white;
        }

        img
        {
            width: 30px;

            &:hover
            {
                cursor: pointer;
            }
        }
    }
</style>