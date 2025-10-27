import axios from 'axios'
const api = axios.create({
    baseURL: 'http://127.0.0.1:8000/api/products/', 
    headers: {
        'Content-Type': 'application/json'
    },
    timeout: 5000 // opcional, tiempo máximo de espera en ms
})

// Puedes agregar interceptores si más adelante usas autenticación (tokens)
api.interceptors.response.use(
    response => response,
    error => {
        console.error('Error en la solicitud Axios:', error)
        return Promise.reject(error)
    }
)

export default api
