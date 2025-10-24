<template>
    <div class="form_container">
        <div class="form">
            <div class="form-object">
                <p>Producto</p>
                <input class="form-input" type="text">
            </div>
            <div class="form-object">
                <p>Identificador</p>
                <input class="form-input" type="text">
            </div>
            <div class="form-object">
                <p>Precio</p>
                <input class="form-input" type="number">
            </div>
        </div>
        <div class="save-button">
            <p>Guardar</p>
        </div>
    </div>
</template>

<script setup lang="ts">

</script>

<style scoped lang="scss">
@import "../assets/styles/colors.scss";

    .form_container
    {
        width: 100%;
        height: 100%;

        display: flex;
        flex-direction: column;
        justify-content: space-evenlycd ;
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