<script setup lang="ts">
import Form from './Components/form.vue';
import List from './Components/list.vue';

</script>

<template>
    <div class="app_container">
        <div class="app">
            <Form class="section"></Form>
            <List class="section"></List>
        </div>
    </div>
</template>

<style scoped lang="scss">
.app_container
{
    width: 100%;
    height: 100%;

    display: flex;
    justify-content: center;
    align-items: center;

    .app
    {
        width: 80%;
        height: 80%;

        display: flex;
        justify-content: space-between;
        align-items: center;

        .section
        {
            width: 47%;
            height: 100%;

            border: 5px solid white;
            border-radius: 50px;
        }
    }
}
</style>
