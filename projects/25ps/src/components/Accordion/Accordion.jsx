import React, { useState } from 'react'
import data from './data'

const Accordion = () => {
  const [selected, setSelected] = useState(null)
  const [btnToggleMulti, setBtnToggleMulti] = useState(false)
  const [multi, setMulti] = useState([])

  const singleSelect = (id) => {
    setSelected(selected === id ? null : id)
    console.log(selected)
  }

  const multiSelect = (id) => {
    let multiList = [...multi]
    const findCurrentId = multiList.indexOf(id)
    if (findCurrentId === -1) {
      multiList.push(id)
    } else {
      multiList.splice(findCurrentId, 1)
    }
    setMulti(multiList)
  }

  // console.log(singleSelect)
  // console.log(selected)

  return (
    <div>
      <button onClick={() => setBtnToggleMulti(!btnToggleMulti)}>
        {btnToggleMulti ? (
          <>Toggle Single Selection</>
        ) : (
          <>Toggle Multi Selection</>
        )}
      </button>
      <div>
        {data && data.length > 0 ? (
          data.map((dataItem) => (
            <div key={dataItem.id}>
              <div
                onClick={
                  btnToggleMulti
                    ? () => multiSelect(dataItem.id)
                    : () => singleSelect(dataItem.id)
                }
              >
                <h2>{dataItem.question}</h2>
                <span>+</span>
              </div>
              {btnToggleMulti
                ? multi.indexOf(dataItem.id) !== -1 && (
                    <div>{dataItem.answer}</div>
                  )
                : selected === dataItem.id && <div>{dataItem.answer}</div>}
            </div>
          ))
        ) : (
          <h2>No Data Was Found!!!</h2>
        )}
      </div>
    </div>
  )
}

export default Accordion
