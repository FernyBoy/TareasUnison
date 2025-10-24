from django.urls import path
from . import views

urlpatterns = [
    path('products/', views.GetProducts, name='get_products'),
    path('products/add/', views.AddProduct, name='add_product'),
    path('products/delete/<str:product_id>/', views.DeleteProduct, name='delete_product'),
]
