import React, { useState } from 'react'
import data from './data'

const Accordion = () => {
  const [selected, setSelected] = useState(null)
  const [btnMultiSelect, setBtnMultiSelect] = useState(false)
  const [multiSelected, setMultiSelected] = useState([])

  const singleSelect = (id) => {
    setSelected(selected === id ? null : id)
  }

  const multiSelect = (id) => {
    let copyList = [...multiSelected]
    const currentId = copyList.indexOf(id)
    if (currentId === -1) copyList.push(id)
    else copyList.splice(currentId, 1)
    setMultiSelected(copyList)
  }

  // console.log(selected)
  // console.log(btnMultiSelect)

  return (
    <div>
      <button onClick={() => setBtnMultiSelect(!btnMultiSelect)}>
        Toggle MultiSelect
      </button>

      <div>
        {data && data.length > 0 ? (
          data.map((dataItem) => (
            <div
              key={dataItem.id}
              onClick={
                btnMultiSelect
                  ? () => multiSelect(dataItem.id)
                  : () => singleSelect(dataItem.id)
              }
            >
              <div>
                <h2>{dataItem.question}</h2>
                <span>+</span>
              </div>
              {btnMultiSelect
                ? multiSelected.indexOf(dataItem.id) !== -1 && (
                    <p>{dataItem.answer}</p>
                  )
                : selected === dataItem.id && <p>{dataItem.answer}</p>}
            </div>
          ))
        ) : (
          <div>
            <h2>Data is not found!!!</h2>
          </div>
        )}
      </div>
    </div>
  )
}

export default Accordion
