from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status
from .models import Products
from .serializers import ProductSerializer


# 📦 Obtener todos los productos
@api_view(['GET'])
def GetProducts(request):
    products = Products.objects.all()
    serializer = ProductSerializer(products, many=True)
    return Response(serializer.data)


# ➕ Agregar un nuevo producto
@api_view(['POST'])
def AddProduct(request):
    serializer = ProductSerializer(data=request.data)
    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data, status=status.HTTP_201_CREATED)
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


# ❌ Eliminar un producto por id
@api_view(['DELETE'])
def DeleteProduct(request, product_id):
    try:
        product = Products.objects.get(id=product_id)
        product.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
    except Products.DoesNotExist:
        return Response({'error': 'Producto no encontrado'}, status=status.HTTP_404_NOT_FOUND)
