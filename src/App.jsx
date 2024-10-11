import './App.css'
import {File} from "./components/File.jsx";
import {Folder} from "./components/Folder.jsx";

function App() {
  return <>
      <div className={"container"}>
          <Folder name={"TestTestTestTestTest"} image={DOSSIER_OUVERT}/>
          <File name={"TestTestTestTestTestFile"} image={PDF}/>
      </div>
  </>
}

export default App
