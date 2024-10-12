import FLECHE from "../images/fleche_retour.png";
import React from "react";

export function Button({path, image, handleBackClick, ...props}) {
    return <>
        <div className={"divRetour"}>
            <button onClick={handleBackClick}>
                <img src={image} alt="Retour"/>
                <p>{path}</p>
            </button>
        </div>
    </>
}