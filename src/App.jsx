import '/src/App.css'
import {File} from "./components/File.jsx";
import {Folder} from "./components/Folder.jsx";
import PDF from '/src/images/pdf.png';
import CODE from '/src/images/code.png';
import CSV from '/src/images/csv.png';
import DOSSIER_OUVERT from '/src/images/dossier_ouvert.png';
import DOSSIER_FERME from '/src/images/dossier_ferme.png';
import FICHIER from '/src/images/fichier.png';
import FLECHE from '/src/images/fleche_retour.png';
import ZIP from '/src/images/zip.png';
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
