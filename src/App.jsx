import '/src/App.css'
import FileExplorer from '/src/components/FileExplorer.jsx';
import { QueryClient, QueryClientProvider } from 'react-query';

// Créer un client React Query
const queryClient = new QueryClient();

function App() {
    return (
        <QueryClientProvider client={queryClient}>
            <div className="container">
                <h1>Mes fichiers</h1>
                <FileExplorer owner="LorisCaruhel" repo="LorisFolder" branch="main" />
            </div>
        </QueryClientProvider>
    );
}

export default App
