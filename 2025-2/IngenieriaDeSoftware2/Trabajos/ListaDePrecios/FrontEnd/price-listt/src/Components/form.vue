<template>
    <div class="form_container">
        <div class="form">
            <div class="form-object">
                <p>Producto</p>
                <input class="form-input" type="text" v-model="product.name">
            </div>
            <div class="form-object">
                <p>Identificador</p>
                <input class="form-input" type="text" v-model="product.id">
            </div>
            <div class="form-object">
                <p>Precio</p>
                <input class="form-input" type="number" v-model="product.price">
            </div>
        </div>
        <div class="save-button" @click="SaveProduct">
            <p>Guardar</p>
        </div>
    </div>
</template>

<script setup lang="ts">
import api from '../../src/axios';
import { ref } from 'vue'
import type { ProductInterface } from '../interfaces/product.interface';

const emit = defineEmits(['product-saved'])

const product = ref<ProductInterface>({
    name: '',
    id: '',
    price: NaN,
})

const SaveProduct = async () => {
    try {
        const response = await api.post('add/', product.value)
        console.log('Producto guardado:', response.data)
        // alert('✅ Producto agregado correctamente')

        emit('product-saved', response.data)

        // Limpiamos los campos
        product.value = { id: '', name: '', price: NaN }

    } 
    catch (error: any) {
        console.error('❌ Error al guardar el producto:', error.response?.data || error)
        alert('Error al guardar el producto. Revisa la consola.')
    }
}
</script>

<style scoped lang="scss">
@import "../assets/styles/colors.scss";

    .form_container
    {
        width: 100%;
        height: 100%;

        display: flex;
        flex-direction: column;
        justify-content: space-evenly;
        align-items: center;

        .form
        {
            width: 90%;
            height: 65%;

            display: flex;
            flex-direction: column;
            justify-content: space-around;
            align-items: center;

            .form-object
            {
                width: 100%;
        
                display: flex;
                justify-content: space-between;
                
                font-size: 3.5rem;

                p
                {
                    width: 30%;
                }

                input
                {
                    width: 45%;
                    padding: 20px;

                    border: 2px solid white;
                    border-radius: 50px;

                    background-color: $blue;

                    color: white;
                    font-size: 2.5rem;
                }

                input[type=number]::-webkit-outer-spin-button,
                input[type=number]::-webkit-inner-spin-button 
                {
                    -webkit-appearance: none;
                }

                input:focus
                {
                    outline: none;
                }
            }
        }

        .save-button
        {
            width: 200px;
            height: 80px;

            display: flex;
            justify-content: center;
            align-items: center;

            border-radius: 50px;

            color: white;
            font-size: 2rem;

            background-color: $golden;
        }
        
        .save-button:hover
        {
            cursor: pointer;
            background-color: $dark-golden;
        }
    }
</style>