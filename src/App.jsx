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

function App() {
  return <>
      <div className={"container"}>
          <Folder name={"TestTestTestTestTest"} image={DOSSIER_OUVERT}/>
          <File name={"TestTestTestTestTestFile"} image={PDF}/>
      </div>
  </>
}

export default App
