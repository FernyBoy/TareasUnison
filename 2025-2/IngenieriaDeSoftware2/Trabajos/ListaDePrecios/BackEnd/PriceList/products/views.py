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
    # Creamos el serializer con los datos recibidos
    serializer = ProductSerializer(data=request.data)

    # Validamos los datos
    if serializer.is_valid():
        # Guardamos el objeto
        try:
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        except Exception as e:
            # Retornamos error si no se puede guardar (por ejemplo, tabla no manejada o restricciones)
            return Response(
                {'error': 'No se pudo guardar el producto', 'details': str(e)},
                status=status.HTTP_400_BAD_REQUEST
            )

    # Si los datos no son válidos, devolvemos los errores
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
