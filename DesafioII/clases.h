    #ifndef CLASES_H
    #define CLASES_H
    #include <string>
    using namespace std;
    class redEstaciones;
    class EstacionServicio {
    private:
        string nombre, codigo, gerente, region;
        string gps[3];
        int regular, premium, ecoExtra;
        int precioRegularN, precioPremiumN, precioEcoExtraN,precioRegularC, precioPremiumC, precioEcoExtraC,precioRegularS,
            precioPremiumS, precioEcoExtraS, PremiumVendido = 0, RegularVendido =0, EcoVendido=0, CantSobrantePremium=0,
            CantSobranteRegular=0, CantSobranteEco=0, regularInicial, premiumInicial, ecoExtraInicial;
        char surtidores, naves;
        string* modeloSurtidor;
        int ventaDiaPremium,ventaDiaRegular,ventaDiaEcoExtra;
        bool* estadoSurtidor;
        string tipoPago;

    public:
        EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region,string gps[3],int &cont);
        void setCantidadCombustible(int _premium,int _regular,int _eco);
        int obtenerCantidadCombustible(const string& tipo) const;
        unsigned char obtenerSurtidores() const;
        unsigned char obtenerNaves() const;
        void ventaCombustible(const string& tipo, float cantidad);
        void modificarSurtidores();
        void asignarModelosSurtidores();
        unsigned char obtenerNaves();
        void asignarEstadoSurtidores();
        void cambiarEstadoSurtidorPorModelo(const string& modelo, bool activar);
        void mostrarSurtidores();
        int contarSurtidoresActivos();
        bool surtidoresActivos();
        void simulacionVentas(int cantidadMaximaVenta);
        void simulacionVentas();
        void verificacionDeFugas();
        string* obtenerModelosSurtidores();
        string obtenerNombre();
        string obtenerCodigo();
        string obtenerGerente();
        string obtenerRegion();
        string obtenerGps();
        void setPrecioPremiumN(int precio);
        void setPrecioRegularN(int precio);
        void setPrecioEcoExtraN(int precio);
        void setPrecioPremiumC(int precio);
        void setPrecioRegularC(int precio);
        void setPrecioEcoExtraC(int precio);
        void setPrecioPremiumS(int precio);
        void setPrecioRegularS(int precio);
        void setPrecioEcoExtraS(int precio);
        int getPrecioPremiumN();
        int getPrecioRegularN();
        int getPrecioEcoExtraN();
        int getPrecioPremiumC();
        int getPrecioRegularC();
        int getPrecioEcoExtraC();
        int getPrecioPremiumS();
        int getPrecioRegularS();
        int getPrecioEcoExtraS();
        int getVentaDiaPremium();
        int getVentaDiaRegular();
        int getVentaDiaEcoExtra();
        void setNombre(string _nombre);
        void setCodigo(string _codigo);
        void setGerente(string _gerente);
    };

    class redEstaciones {
    private:
        EstacionServicio** estaciones;
        int ventasPremiumT=0,ventasRegularT=0,ventasEcoExtraT=0;
        string fijarPrecio[3][3];
        int cantEstaciones,cantVentas;

    public:
        redEstaciones();
        void agregarEstacion(EstacionServicio* nuevaEstacion);
        void eliminarEstacion(string& cod);
        void fijarPrecioCombustible();
        void getredEstaciones();
        string getCodigo(int index);
        void precios();
        void obtenerPrecios(string region, string codigo);
        EstacionServicio** getRedEstaciones();
        void mostrarRedEstaciones();
        int getCantEstaciones();
        void setNombreEstacion(string _codigo,string nombre);
        void setCodigoEstacion(string _codigo,string codigo);
        void setGerenteEstacion(string _codigo,string gerente);
        void modificarSurtidoresRed(string _codigo);
        void modificarEstadoRed(string codigo);
        void simulacionVentasEstacion(string codigo);
        void simulacionVentasRed();
        void simulacionVentasSurtidorRed(string codigo);
        void verificacionDeFugas(string codigo);
        int getCantVentas();
        int getVentasPremiumT();
        int getVentasRegularT();
        int getVentasEcoExtraT();
    };

    #endif // CLASES_H
